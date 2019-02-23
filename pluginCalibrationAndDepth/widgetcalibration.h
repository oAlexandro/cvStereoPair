#ifndef WIDGETCALIBRATION_H
#define WIDGETCALIBRATION_H

#include <QWidget>

#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

namespace Ui {
class WidgetCalibration;
}

class WidgetCalibration : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetCalibration(QWidget *parent = nullptr);
    ~WidgetCalibration();

public slots:
    void stereoCalibration(const std::vector<std::string>& imagelist, cv::Size boardSize,
                           float squareSize, bool displayCorners = false, bool useCalibrated=true, bool showRectified=true);


private slots:
    void on_b_displayCorners_clicked();

    void on_b_calibration_clicked();

    void on_b_Undistortion_clicked();

private:
    Ui::WidgetCalibration *ui;
    bool useCalibrated;
};

#endif // WIDGETCALIBRATION_H
