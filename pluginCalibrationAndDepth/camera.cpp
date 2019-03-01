#include "camera.h"
#include "ui_camera.h"
#include <QPixmap>
#include <QFile>
#include <QDebug>
using namespace cv;
using std::cout; using std::cerr; using std::endl;

Camera::Camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    //connect(this,SIGNAL(startCamera()),this,SLOT(onCamera()));
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onCamera()));
}

Camera::~Camera()
{
    delete ui;
}

void Camera::onCamera()
{
    //m_close = false;

    //QImage leftImage, rightImage;
    //QPixmap leftPixmap, rightPixmap;

    //VideoCapture capture(0); // open the first camera
    if (!m_capture.isOpened() && m_capture2.isOpened())
    {
        cerr << "ERROR: Can't initialize camera capture" << endl;
    }

//    for (;;)
//    {
        m_capture >> m_dst; // read the next frame from camera
        m_capture2 >> m_dst2;
        if (!(m_dst.empty() && m_dst2.empty()))
        {
            flip(m_dst, m_frame, 1);
            flip(m_dst2, m_frame2, 1);
            cv::cvtColor(m_frame, m_frame, cv::COLOR_BGR2RGB);
            cv::cvtColor(m_frame2, m_frame2, cv::COLOR_BGR2RGB);
            emit sendFrameToLeftInput(m_frame);
            emit sendFrameToRightInput(m_frame2);
        }


//        if(frame.channels() == 3 && frame2.channels() == 3) {
//                leftImage = QImage(frame.data,frame.cols,frame.rows,static_cast<int>(frame.step), QImage::Format_RGB888);
//                rightImage = QImage(frame2.data,frame2.cols,frame2.rows,static_cast<int>(frame2.step),QImage::Format_RGB888);
//            } else {
//                leftImage = QImage(frame.data, frame.cols,frame.rows, static_cast<int>(frame.step),QImage::Format_Indexed8);
//                rightImage = QImage(frame2.data, frame2.cols,frame2.rows, static_cast<int>(frame2.step),QImage::Format_Indexed8);
//            }
//        leftPixmap = QPixmap::fromImage(leftImage);
//        rightPixmap = QPixmap::fromImage(rightImage);
//        ui->label_camera1->setAlignment(Qt::AlignCenter);
//        ui->label_camera1->setPixmap(leftPixmap.scaled(ui->label_camera1->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
//        ui->label_camera2->setAlignment(Qt::AlignCenter);
//        ui->label_camera2->setPixmap(rightPixmap.scaled(ui->label_camera2->size(), Qt::KeepAspectRatio, Qt::FastTransformation));

//        if(m_close){
//            break;
//        }
//        waitKey(0);


//    }
}

void Camera::startTimer()
{
    m_timer.start(35);
    cout << "Opening camera..." << endl;
    m_capture.open(0);
    m_capture2.open(1);
}

void Camera::stopTimer()
{
    m_timer.stop();
    //m_capture.release();
    //m_capture2.release();
}

void Camera::manualFrame()
{
    qDebug("manualFrame");
    emit sendFrameToLeftOutput(m_frame);
    emit sendFrameToRightOutput(m_frame2);
    m_fileName = m_dirName + '/' + "left" + QString::number(m_counter) + ".png";
    m_fileName2 = m_dirName + '/' + "right" + QString::number(m_counter) + ".png";
//    m_fileName = m_dirName + '/' + "left01.png";
//    m_fileName2 = m_dirName + '/' + "right01.png";
    m_counter++;
    qDebug()<<m_fileName;
    imwrite(m_fileName.toUtf8().constData(), m_frame);
    imwrite(m_fileName2.toUtf8().constData(), m_frame2);


}

void Camera::getDir(QString _dirName)
{
    qDebug("getDir");
    m_dirName = _dirName;
}
