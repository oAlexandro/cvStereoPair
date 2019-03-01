#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

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

private:
    Ui::Camera *ui;
};

#endif // CAMERA_H
