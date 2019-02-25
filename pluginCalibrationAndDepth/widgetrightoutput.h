#ifndef WIDGETRIGHTOUTPUT_H
#define WIDGETRIGHTOUTPUT_H

#include <QWidget>

#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

namespace Ui {
class WidgetRightOutput;
}

class WidgetRightOutput : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetRightOutput(QWidget *parent = nullptr);
    ~WidgetRightOutput();

private:
    Ui::WidgetRightOutput *ui;

public slots:
    void showImage(cv::Mat img1);
};

#endif // WIDGETRIGHTOUTPUT_H
