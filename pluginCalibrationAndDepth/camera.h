#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>
#include <QTimer>

namespace Ui {
class Camera;
}

class Camera : public QWidget
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = nullptr);
    ~Camera();

public slots:
    void onCamera();
    void startTimer();
    void stopTimer();
    void manualFrame();
    void getDir(QString);
    void autoFrame();
    void saveFrames(cv::Mat, cv::Mat);

signals:
    void startCamera();
    void sendFrameToLeftInput(cv::Mat);
    void sendFrameToRightInput(cv::Mat);
    void sendFrameToLeftOutput(cv::Mat);
    void sendFrameToRightOutput(cv::Mat);
    void sendStrToStatus(QString);
    void sendFramesToDetection(cv::Mat, cv::Mat);

private:
    Ui::Camera *ui;
    cv::VideoCapture m_capture;
    cv::VideoCapture m_capture2;
    int m_key;
    bool m_close;
    QTimer m_timer;
    cv::Mat m_frame, m_frame2, m_dst, m_dst2;
    QString m_dirName;
    QString m_fileName, m_fileName2;
    int m_counter = 1;
    QString m_str;
    bool m_autoFrame = false; // поменять на false
    cv::Size m_boardSize;
    size_t m_nFrames = 0;
};

#endif // CAMERA_H
