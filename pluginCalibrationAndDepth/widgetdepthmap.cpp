#include "widgetdepthmap.h"
#include "ui_widgetdepthmap.h"
#include "windowdepthmap.h"

using namespace cv;
using namespace std;

WidgetDepthMap::WidgetDepthMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetDepthMap)
{
    ui->setupUi(this);
}

WidgetDepthMap::~WidgetDepthMap()
{
    delete ui;
}

void WidgetDepthMap::depthMapping(cv::Mat img1, cv::Mat img2)
{
    cout << "start testFunc" << endl;
    std::string img1_filename = "";
    std::string img2_filename = "";
    std::string intrinsic_filename = "";
    std::string extrinsic_filename = "";
    std::string disparity_filename = "";
    std::string point_cloud_filename = "";

    enum { STEREO_BM=0, STEREO_SGBM=1, STEREO_HH=2, STEREO_VAR=3, STEREO_3WAY=4 };
    int alg = STEREO_SGBM;
    int SADWindowSize, numberOfDisparities;
    bool no_display;
    float scale = 1.f;

    Ptr<StereoBM> bm = StereoBM::create(16,9);
    Ptr<StereoSGBM> sgbm = StereoSGBM::create(0,16,3);

    int color_mode = alg == STEREO_BM ? 0 : -1;
    //Mat img1 = imread(img1_filename, color_mode);
    //Mat img2 = imread(img2_filename, color_mode);

    //    Mat img1=imread("aloeL.jpg");
    //    Mat img2=imread("aloeR.jpg");

    if (img1.empty())
    {
        printf("Command-line parameter error: could not load the first input image file\n");

    }
    if (img2.empty())
    {
        printf("Command-line parameter error: could not load the second input image file\n");

    }

    if (scale != 1.f)
    {
        Mat temp1, temp2;
        int method = scale < 1 ? INTER_AREA : INTER_CUBIC;
        cv::resize(img1, temp1, Size(), scale, scale, method);
        img1 = temp1;
        cv::resize(img2, temp2, Size(), scale, scale, method);
        img2 = temp2;
    }

    Size img_size = img1.size();

    Rect roi1, roi2;
    Mat Q;

    if( !intrinsic_filename.empty() )
    {
        // reading intrinsic parameters
        FileStorage fs(intrinsic_filename, FileStorage::READ);
        if(!fs.isOpened())
        {
            printf("Failed to open file %s\n", intrinsic_filename.c_str());

        }

        Mat M1, D1, M2, D2;
        fs["M1"] >> M1;
        fs["D1"] >> D1;
        fs["M2"] >> M2;
        fs["D2"] >> D2;

        M1 *= scale;
        M2 *= scale;

        fs.open(extrinsic_filename, FileStorage::READ);
        if(!fs.isOpened())
        {
            printf("Failed to open file %s\n", extrinsic_filename.c_str());

        }

        Mat R, T, R1, P1, R2, P2;
        fs["R"] >> R;
        fs["T"] >> T;

        stereoRectify( M1, D1, M2, D2, img_size, R, T, R1, R2, P1, P2, Q, CALIB_ZERO_DISPARITY, -1, img_size, &roi1, &roi2 );

        Mat map11, map12, map21, map22;
        initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);
        initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);

        Mat img1r, img2r;
        remap(img1, img1r, map11, map12, INTER_LINEAR);
        remap(img2, img2r, map21, map22, INTER_LINEAR);

        img1 = img1r;
        img2 = img2r;
    }

    numberOfDisparities = numberOfDisparities > 0 ? numberOfDisparities : ((img_size.width/8) + 15) & -16;
    bm->setROI1(roi1);
    bm->setROI2(roi2);
    bm->setPreFilterCap(31);
    bm->setBlockSize(SADWindowSize > 0 ? SADWindowSize : 9);
    bm->setMinDisparity(0);
    bm->setNumDisparities(numberOfDisparities);
    bm->setTextureThreshold(10);
    bm->setUniquenessRatio(15);
    bm->setSpeckleWindowSize(100);
    bm->setSpeckleRange(32);
    bm->setDisp12MaxDiff(1);

    sgbm->setPreFilterCap(63);
    int sgbmWinSize = SADWindowSize > 0 ? SADWindowSize : 3;
    sgbm->setBlockSize(sgbmWinSize);

    int cn = img1.channels();

    sgbm->setP1(8*cn*sgbmWinSize*sgbmWinSize);
    sgbm->setP2(32*cn*sgbmWinSize*sgbmWinSize);
    sgbm->setMinDisparity(0);
    sgbm->setNumDisparities(numberOfDisparities);
    sgbm->setUniquenessRatio(10);
    sgbm->setSpeckleWindowSize(m_number);
    sgbm->setSpeckleRange(32);
    sgbm->setDisp12MaxDiff(1);
    if(alg==STEREO_HH)
        sgbm->setMode(StereoSGBM::MODE_HH);
    else if(alg==STEREO_SGBM)
        sgbm->setMode(StereoSGBM::MODE_SGBM);
    else if(alg==STEREO_3WAY)
        sgbm->setMode(StereoSGBM::MODE_SGBM_3WAY);

    Mat disp, disp8;
    //Mat img1p, img2p, dispp;
    //copyMakeBorder(img1, img1p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);
    //copyMakeBorder(img2, img2p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);

    int64 t = getTickCount();
    if( alg == STEREO_BM )
        bm->compute(img1, img2, disp);
    else if( alg == STEREO_SGBM || alg == STEREO_HH || alg == STEREO_3WAY )
        sgbm->compute(img1, img2, disp);
    t = getTickCount() - t;
    printf("Time elapsed: %fms\n", t*1000/getTickFrequency());



    //disp = dispp.colRange(numberOfDisparities, img1p.cols);
    if( alg != STEREO_VAR )
        disp.convertTo(disp8, CV_8U, 255/(numberOfDisparities*16.));
    else
        disp.convertTo(disp8, CV_8U);
    //    if( !no_display )
    //    {
    //        namedWindow("left", 1);
    //        imshow("left", img1);
    //        namedWindow("right", 1);
    //        imshow("right", img2);
    //namedWindow("disparity", 0);
    imshow("disparity", disp8);
    printf("press any key to continue...");
    fflush(stdout);
    //waitKey();
    printf("\n");
    //    }

    if(!disparity_filename.empty())
        imwrite(disparity_filename, disp8);

    if(!point_cloud_filename.empty())
    {
        printf("storing the point cloud...");
        fflush(stdout);
        Mat xyz;
        reprojectImageTo3D(disp, xyz, Q, true);
        imshow("point Cloud", xyz);
        saveXYZ(point_cloud_filename.c_str(), xyz);
        printf("\n");
    }
    //    Mat xyz;
    //    reprojectImageTo3D(disp, xyz, Q, true);
    //    imshow("point Cloud", xyz);
    cout << "end" << endl;
    //cvWaitKey(0);

}

void WidgetDepthMap::saveXYZ(const char *filename, const Mat &mat)
{
    const double max_z = 1.0e4;
    FILE* fp = fopen(filename, "wt");
    for(int y = 0; y < mat.rows; y++)
    {
        for(int x = 0; x < mat.cols; x++)
        {
            Vec3f point = mat.at<Vec3f>(y, x);
            if(fabs(point[2] - max_z) < FLT_EPSILON || fabs(point[2]) > max_z) continue;
            fprintf(fp, "%f %f %f\n", point[0], point[1], point[2]);
        }
    }
    fclose(fp);
}

void WidgetDepthMap::depthMapOptions(int number)
{
     m_number=number;
}

void WidgetDepthMap::on_b_startDepthMap_clicked()
{
    WindowDepthMap windowdepthmap;
    windowdepthmap.setModal(true);
    windowdepthmap.exec();
}
