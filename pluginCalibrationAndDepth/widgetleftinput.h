#ifndef WIDGETLEFTINPUT_H
#define WIDGETLEFTINPUT_H

#include <QWidget>

#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

namespace Ui {
class WidgetLeftInput;
}

class WidgetLeftInput : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetLeftInput(QWidget *parent = nullptr);
    ~WidgetLeftInput();

private:
    Ui::WidgetLeftInput *ui;

public slots:
    void showImage(cv::Mat img1);
};

#endif // WIDGETLEFTINPUT_H
