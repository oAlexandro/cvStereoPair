#include "camera.h"
#include "ui_camera.h"
#include <QDebug>
using namespace cv;
using namespace std;
Camera::Camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onCamera()));
    m_boardSize.width = 9;
    m_boardSize.height = 6;
}

Camera::~Camera()
{
    delete ui;
}

void Camera::onCamera()
{
    if (!m_capture.isOpened() && m_capture2.isOpened())
    {
        m_str = "- ERROR: Can't initialize camera capture";
        emit sendStrToStatus(m_str);
    }
    m_capture >> m_dst; // read the next frame from camera
    m_capture2 >> m_dst2;
    m_nFrames++;
    if (!(m_dst.empty() && m_dst2.empty()))
    {
        flip(m_dst, m_frame, 1);
        flip(m_dst2, m_frame2, 1);
        cv::cvtColor(m_frame, m_frame, cv::COLOR_BGR2RGB);
        cv::cvtColor(m_frame2, m_frame2, cv::COLOR_BGR2RGB);
        emit sendFrameToLeftInput(m_frame);
        emit sendFrameToRightInput(m_frame2);
    }
    if (m_nFrames % 60 == 0)
    {
        if(m_autoFrame){
            emit sendFramesToDetection(m_frame, m_frame2);
        }
        m_nFrames = 0;
    }
}

void Camera::startTimer()
{
    m_timer.start(35);
    m_str = "- Opening camera...";
    emit sendStrToStatus(m_str);
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
    emit sendFrameToLeftOutput(m_frame);
    emit sendFrameToRightOutput(m_frame2);
    saveFrames(m_frame, m_frame2);
//    m_fileName = m_dirName + '/' + "left" + QString::number(m_counter) + ".png";
//    m_fileName2 = m_dirName + '/' + "right" + QString::number(m_counter) + ".png";
//    m_counter++;
//    imwrite(m_fileName.toUtf8().constData(), m_frame);
//    imwrite(m_fileName2.toUtf8().constData(), m_frame2);
}

void Camera::getDir(QString _dirName)
{
    m_dirName = _dirName;
}

void Camera::autoFrame()
{
    m_autoFrame = true;

}

void Camera::saveFrames(Mat _frame, Mat _frame2)
{
//    cvtColor(_frame, _frame, COLOR_GRAY2RGB);
//    cvtColor(_frame2, _frame2, COLOR_GRAY2RGB);
    m_fileName = m_dirName + '/' + "left" + QString::number(m_counter) + ".png";
    m_fileName2 = m_dirName + '/' + "right" + QString::number(m_counter) + ".png";
    m_counter++;
    imwrite(m_fileName.toUtf8().constData(), _frame);
    imwrite(m_fileName2.toUtf8().constData(), _frame2);
}
