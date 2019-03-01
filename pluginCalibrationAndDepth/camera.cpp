#include "camera.h"
#include "ui_camera.h"
#include <QPixmap>

using namespace cv;
using std::cout; using std::cerr; using std::endl;

Camera::Camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
}

Camera::~Camera()
{
    delete ui;
}

void Camera::onCamera()
{
    Mat frame, dst;
    cout << "Opening camera..." << endl;
    VideoCapture capture(0); // open the first camera
    if (!capture.isOpened())
    {
        cerr << "ERROR: Can't initialize camera capture" << endl;
    }

    cout << "Frame width: " << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
    cout << "     height: " << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
    cout << "Capturing FPS: " << capture.get(CAP_PROP_FPS) << endl;

    cout << endl << "Press 'ESC' to quit, 'space' to toggle frame processing" << endl;
    cout << endl << "Start grabbing..." << endl;

    size_t nFrames = 0;
    int64 t0 = cv::getTickCount();
    int64 processingTime = 0;
    for (;;)
    {
        capture >> dst; // read the next frame from camera
        if (dst.empty())
        {
            cerr << "ERROR: Can't grab camera frame." << endl;
            break;
        }
        flip(dst, frame, 1);
        nFrames++;
        if (nFrames % 10 == 0)
        {
            const int N = 10;
            int64 t1 = cv::getTickCount();
            cout << "Frames captured: " << cv::format("%5lld", (long long int)nFrames)
                 << "    Average FPS: " << cv::format("%9.1f", (double)getTickFrequency() * N / (t1 - t0))
                 << "    Average time per frame: " << cv::format("%9.2f ms", (double)(t1 - t0) * 1000.0f / (N * getTickFrequency()))
                 << "    Average processing time: " << cv::format("%9.2f ms", (double)(processingTime) * 1000.0f / (N * getTickFrequency()))
                 << std::endl;
            t0 = t1;
            processingTime = 0;
        }
        imshow("Frame", frame);
        QImage leftImage;
        QPixmap leftPixmap;
        if(frame.channels() == 3) {
                leftImage = QImage(frame.data,frame.cols,frame.rows,static_cast<int>(frame.step),QImage::Format_RGB888);
            } else {
                leftImage = QImage(frame.data, frame.cols,frame.rows, static_cast<int>(frame.step),QImage::Format_Indexed8);
            }
        leftPixmap = QPixmap::fromImage(leftImage);
        ui->label_camera->setAlignment(Qt::AlignCenter);
        ui->label_camera->setPixmap(leftPixmap.scaled(ui->label_camera->size(), Qt::KeepAspectRatio, Qt::FastTransformation));

        int key = waitKey(1);
        if (key == 27/*ESC*/)
            break;

    }
    std::cout << "Number of captured frames: " << nFrames << endl;
}
