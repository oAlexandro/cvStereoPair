#include "widgetdepthmap.h"
#include "ui_widgetdepthmap.h"
#include <QtDebug>
#include <opencv2/stereo.hpp>

#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/ximgproc.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace cv::ximgproc;
using namespace std;

using namespace cv;
using namespace std;

int main(int argc, char** argv);
Rect computeROI(Size2i src_sz, Ptr<StereoMatcher> matcher_instance);



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


/*void WidgetDepthMap::depthMapping(cv::Mat img1, cv::Mat img2)
//{
//    //cv::Mat img1 = _img1;
//    //cv::Mat img2 = _img2;
//    //cvtColor(img1, img1, CV_RGB2GRAY);
//    //cvtColor(img2, img2, CV_RGB2GRAY);

//    //imshow("img1",img11);
//    //imshow("img2",img22);

//    std::string img1_filename = "";
//    std::string img2_filename = "";
//    std::string intrinsic_filename = "";
//    std::string extrinsic_filename = "";
//    std::string disparity_filename = "";
//    std::string point_cloud_filename = "";

//    enum { STEREO_BM=0, STEREO_SGBM=1, STEREO_HH=2, STEREO_VAR=3, STEREO_3WAY=4 };
//    int alg = STEREO_SGBM;
//    int SADWindowSize, numberOfDisparities;

//    float scale = 1.f;

//    Ptr<StereoBM> bm = StereoBM::create(16,9);
//    Ptr<StereoSGBM> sgbm = StereoSGBM::create(0,16,3);

//    //int color_mode = alg == STEREO_BM ? 0 : -1;
//    //Mat img1 = imread(img1_filename, color_mode);
//    //Mat img2 = imread(img2_filename, color_mode);

//    //    Mat img1=imread("aloeL.jpg");
//    //    Mat img2=imread("aloeR.jpg");

//    if (img1.empty())
//    {
//        printf("Command-line parameter error: could not load the first input image file\n");

//    }
//    if (img2.empty())
//    {
//        printf("Command-line parameter error: could not load the second input image file\n");

//    }

//    if (scale != 1.f)
//    {
//        Mat temp1, temp2;
//        int method = scale < 1 ? INTER_AREA : INTER_CUBIC;
//        cv::resize(img1, temp1, Size(), scale, scale, method);
//        img1 = temp1;
//        cv::resize(img2, temp2, Size(), scale, scale, method);
//        img2 = temp2;
//    }

//    Size img_size = img1.size();

//    Rect roi1, roi2;
//    Mat Q;

//    if( !intrinsic_filename.empty() )
//    {
//        // reading intrinsic parameters
//        FileStorage fs(intrinsic_filename, FileStorage::READ);
//        if(!fs.isOpened())
//        {
//            printf("Failed to open file %s\n", intrinsic_filename.c_str());

//        }

//        Mat M1, D1, M2, D2;
//        fs["M1"] >> M1;
//        fs["D1"] >> D1;
//        fs["M2"] >> M2;
//        fs["D2"] >> D2;

//        M1 *= scale;
//        M2 *= scale;

//        fs.open(extrinsic_filename, FileStorage::READ);
//        if(!fs.isOpened())
//        {
//            printf("Failed to open file %s\n", extrinsic_filename.c_str());

//        }

//        Mat R, T, R1, P1, R2, P2;
//        fs["R"] >> R;
//        fs["T"] >> T;

//        stereoRectify( M1, D1, M2, D2, img_size, R, T, R1, R2, P1, P2, Q, CALIB_ZERO_DISPARITY, -1, img_size, &roi1, &roi2 );

//        Mat map11, map12, map21, map22;
//        initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);
//        initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);

//        Mat img1r, img2r;
//        remap(img1, img1r, map11, map12, INTER_LINEAR);
//        remap(img2, img2r, map21, map22, INTER_LINEAR);

//        img1 = img1r;
//        img2 = img2r;
//    }

//    //numberOfDisparities = numberOfDisparities > 0 ? numberOfDisparities : ((img_size.width/8) + 15) & -16;
//    //numberOfDisparities = 96;
//    bm->setROI1(roi1);
//    bm->setROI2(roi2);
//    bm->setPreFilterCap(31);
//    bm->setBlockSize(SADWindowSize > 0 ? SADWindowSize : 9);
//    bm->setMinDisparity(0);
//    bm->setNumDisparities(numberOfDisparities);
//    bm->setTextureThreshold(10);
//    bm->setUniquenessRatio(15);
//    bm->setSpeckleWindowSize(100);
//    bm->setSpeckleRange(32);
//    bm->setDisp12MaxDiff(1);

//    sgbm->setPreFilterCap(63);
//    int sgbmWinSize = SADWindowSize > 0 ? SADWindowSize : 3;
//    sgbm->setBlockSize(sgbmWinSize);

//    int cn = img1.channels();

//    sgbm->setP1(8*cn*sgbmWinSize*sgbmWinSize);
//    sgbm->setP2(32*cn*sgbmWinSize*sgbmWinSize);
//    sgbm->setMinDisparity(0);
//    sgbm->setNumDisparities(numberOfDisparities);
//    sgbm->setUniquenessRatio(10);
//    sgbm->setSpeckleWindowSize(100);
//    sgbm->setSpeckleRange(32);
//    sgbm->setDisp12MaxDiff(1);
//    if(alg==STEREO_HH)
//        sgbm->setMode(StereoSGBM::MODE_HH);
//    else if(alg==STEREO_SGBM)
//        sgbm->setMode(StereoSGBM::MODE_SGBM);
//    else if(alg==STEREO_3WAY)
//        sgbm->setMode(StereoSGBM::MODE_SGBM_3WAY);

//    Mat disp, disp8;
//    //Mat img1p, img2p, dispp;
//    //copyMakeBorder(img1, img1p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);
//    //copyMakeBorder(img2, img2p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);

//    int64 t = getTickCount();
//    if( alg == STEREO_BM )
//        bm->compute(img1, img2, disp);
//    else if( alg == STEREO_SGBM || alg == STEREO_HH || alg == STEREO_3WAY )
//        sgbm->compute(img1, img2, disp);
//    t = getTickCount() - t;
//    //printf("Time elapsed: ", t*1000/getTickFrequency());



//    //disp = dispp.colRange(numberOfDisparities, img1p.cols);
//    if( alg != STEREO_VAR )
//        disp.convertTo(disp8, CV_8U, 255/(numberOfDisparities*16.));
//    else
//        disp.convertTo(disp8, CV_8U);
//    //    if( !no_display )
//    //    {
//    //        namedWindow("left", 1);
//    //        imshow("left", img1);
//    //        namedWindow("right", 1);
//    //        imshow("right", img2);
//    //namedWindow("disparity", 0);
//  //  imshow("disparity", disp8);
//   // QImage m_outputImage = QImage(disp8.data, disp8.cols,disp8.rows, static_cast<int>(disp8.step),QImage::Format_Indexed8);
////if(!disp8.empty())
////{
////    qDebug("!empty");
//    imshow("disp8",disp8);
//    emit picture(disp8);


////}

//    printf("press any key to continue...");
//    fflush(stdout);
//    //waitKey();
//    printf("\n");
//    //    }

//    if(!disparity_filename.empty())
//        imwrite(disparity_filename, disp8);

//    if(!point_cloud_filename.empty())
//    {
//        printf("storing the point cloud...");
//        fflush(stdout);
//        Mat xyz;
//        reprojectImageTo3D(disp, xyz, Q, true);
//        imshow("point Cloud", xyz);
//        saveXYZ(point_cloud_filename.c_str(), xyz);
//        printf("\n");
//    }
//    //    Mat xyz;
//    //    reprojectImageTo3D(disp, xyz, Q, true);
//    //    imshow("point Cloud", xyz);
//    //cvWaitKey(0);

//}
*/

// Второй способ DM
void WidgetDepthMap::depthMapping()
{
   // qDebug()<<("Parametr_1")<<par_1;
    //qDebug()<<("Parametr_2")<<par_1;

    //    Mat im_left=imread("left01.jpg");
    //    Mat im_right=imread("right01.jpg");

        cv::Size imagesize = image_left.size();
        cv::Mat disparity_left=cv::Mat(imagesize.height,imagesize.width,CV_16S);
        cv::Mat disparity_right=cv::Mat(imagesize.height,imagesize.width,CV_16S);
        cv::Mat g1,g2,disp,disp8;
        cv::cvtColor(image_left,g1,cv::COLOR_BGR2GRAY);
        cv::cvtColor(image_right,g2,cv::COLOR_BGR2GRAY);


    //    cv::Ptr<cv::StereoBM> sbm = cv::StereoBM::create(0,21);
    //    sbm->setDisp12MaxDiff(1);
    //    sbm->setSpeckleRange(8);
    //    sbm->setSpeckleWindowSize(9);
    //    sbm->setUniquenessRatio(0);
    //    sbm->setTextureThreshold(607);
    //    sbm->setMinDisparity(0);
    //    sbm->setPreFilterCap(30);
    //    sbm->setPreFilterSize(7);
    //    sbm->compute(g1,g2,disparity_left);


        Ptr<StereoSGBM> sgbm = StereoSGBM::create(parametr_1,    //int minDisparity
                                                parametr_2,     //int numDisparities
                                                parametr_3,      //int SADWindowSize
                                                parametr_4,    //int P1 = 0
                                                parametr_5,   //int P2 = 0
                                                parametr_6,     //int disp12MaxDiff = 0
                                                parametr_7,     //int preFilterCap = 0
                                                parametr_8,      //int uniquenessRatio = 0
                                                parametr_9,    //int speckleWindowSize = 0
                                                parametr_10,     //int speckleRange = 0
                                                paramet);  //bool fullDP = false


        //Ptr<StereoSGBM> sgbm = StereoSGBM::create(0,    //int minDisparity
        //                                        96,     //int numDisparities
        //                                        11,      //int SADWindowSize
        //                                        100,    //int P1 = 0
        //                                        2400,   //int P2 = 0
        //                                       20,     //int disp12MaxDiff = 0
        //                                        16,     //int preFilterCap = 0
        //                                        1,      //int uniquenessRatio = 0
        //                                        100,    //int speckleWindowSize = 0
        //                                        20,     //int speckleRange = 0
        //                                        true);  //bool fullDP = false
        //Ptr<StereoSGBM> sgbm = StereoSGBM::create(0, 96, 11);
        //Ptr< cv::stereo::StereoBinarySGBM > test_sgbm = cv::stereo::StereoBinarySGBM::create(0, 16, 7);
        //test_sgbm->compute(g1,g2,disparity_left);

        sgbm->compute(g1, g2, disparity_left);
        normalize(disparity_left, disp8, 0, 255, CV_MINMAX, CV_8U);
    //    cv::namedWindow("Left",CV_WINDOW_FREERATIO);
        //cv::imshow("Left", im_left);
    //    cv::namedWindow("Right",CV_WINDOW_FREERATIO);
        //cv::imshow("Right", im_right);
    //    cv::namedWindow("Depth map",CV_WINDOW_FREERATIO);
        //cv::imshow("Depth map", disp8);
        //cv::waitKey(0);
        qDebug("Готовая фотография");
        emit picture(disp8);

       //  int max_disp = 160;
        // int wsize;

               Mat left_for_matcher, right_for_matcher;
               Mat left_disp,right_disp;
               left_disp=disparity_left;
               right_disp=disparity_right;
               Mat filtered_disp,solved_disp,solved_filtered_disp;
               double matching_time, filtering_time;
               left_for_matcher=image_left;
               right_for_matcher=image_right;
               Ptr<DisparityWLSFilter> wls_filter;




              //  Ptr <StereoBM> left_matcher = StereoBM :: create (160, -1); //max_disp, wsize
              //  sgbm = StereoSGBM :: create (160, -1); //max_disp, wsize
                wls_filter = createDisparityWLSFilter (sgbm);
                Ptr <StereoMatcher> right_matcher = createRightMatcher (sgbm);




                matching_time = (double)getTickCount();
                sgbm-> compute(left_for_matcher, right_for_matcher,left_disp);
                right_matcher->compute(right_for_matcher,left_for_matcher, right_disp);
                matching_time = ((double)getTickCount() - matching_time)/getTickFrequency();




                    //Фильтрация
                        wls_filter->setLambda(8000.0);
                        qDebug("noooooo");
                        wls_filter->setSigmaColor(1.5);
                        filtering_time = (double)getTickCount();
                        wls_filter->filter(left_disp,image_left,filtered_disp,right_disp);
                        filtering_time = ((double)getTickCount() - filtering_time)/getTickFrequency();



                        Mat raw_disp_vis;

                               getDisparityVis(left_disp,raw_disp_vis,1.0);
                               namedWindow("raw disparity", WINDOW_AUTOSIZE);
                               imshow("raw disparity", raw_disp_vis);
                               Mat filtered_disp_vis;
                               getDisparityVis(filtered_disp,filtered_disp_vis,1.0);
                               namedWindow("filtered disparity", WINDOW_AUTOSIZE);
                               imshow("filtered disparity", filtered_disp_vis);
                               if(!solved_disp.empty())
                               {
                                   Mat solved_disp_vis;
                                   getDisparityVis(solved_disp,solved_disp_vis,1.0);
                                   namedWindow("solved disparity", WINDOW_AUTOSIZE);
                                   imshow("solved disparity", solved_disp_vis);
                                   Mat solved_filtered_disp_vis;
                                   getDisparityVis(solved_filtered_disp,solved_filtered_disp_vis,1.0);
                                   namedWindow("solved wls disparity", WINDOW_AUTOSIZE);
                                   imshow("solved wls disparity", solved_filtered_disp_vis);
                               }
                               while(1)
                               {
                                   char key = (char)waitKey();
                                   if( key == 27 || key == 'q' || key == 'Q') // 'ESC'
                                   {}
                                 }



}


void WidgetDepthMap::saveXYZ(const char *   filename, const Mat &mat)
{
    const double max_z = 1.0e4;
    FILE* fp = fopen(filename, "wt");
    for(int y = 0; y < mat.rows; y++)
    {
        qDebug("Файл открыт");
        for(int x = 0; x < mat.cols; x++)
        {
            Vec3f point = mat.at<Vec3f>(y, x);
            if(fabs(point[2] - max_z) < FLT_EPSILON || fabs(point[2]) > max_z) continue;
            fprintf(fp, "%f %f %f\n", point[0], point[1], point[2]);
        }
    }
    fclose(fp);
}

void WidgetDepthMap::depthMapOptions(int &number_1, int &number_2, int &number_3, int &number_4, int &number_5, int &number_6, int &number_7, int &number_8, int &number_9, int &number_10, bool &insinuation)
{
    parametr_1=number_1;
    parametr_2=number_2;
    parametr_3=number_3;
    parametr_4=number_4;
    parametr_5=number_5;
    parametr_6=number_6;
    parametr_7=number_7;
    parametr_8=number_8;
    parametr_9=number_9;
    parametr_10=number_10;
    paramet=insinuation;
}




void WidgetDepthMap::on_b_startDepthMap_clicked()
{

    emit sendStartSignal();

}

void WidgetDepthMap::on_b_updateSet_clicked()
{

}
void WidgetDepthMap::Image(Mat img_left, Mat img_right)
{
    image_left=img_left;
    image_right=img_right;
}

void WidgetDepthMap::on_b_settingsDepthMap_clicked()
{

}


































