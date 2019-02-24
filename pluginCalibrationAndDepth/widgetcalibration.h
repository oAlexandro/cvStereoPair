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
//    void stereoCalibration(const std::vector<std::string>& imagelist, cv::Size boardSize,
//                           float squareSize, bool displayCorners, bool useCalibrated, bool showRectified);
    //void stereoCalibration(const std::vector<std::string>& imagelist, cv::Size boardSize, float squareSize);
    void stereoCalibration();
    void getImagelist(const std::vector<std::string>& _imagelist);
    void getBoardSize(cv::Size _boardSize);
    void getSquareSize(float _squareSize);

signals:


private slots:
    void on_b_Undistortion_clicked();
    void on_cb_displayCorners_stateChanged(int arg1);
    void on_rb_Bouguet_clicked();
    void on_rb_Hartley_clicked();

private:
    Ui::WidgetCalibration *ui;
    bool m_displayCorners = false;
    bool m_useCalibrated = true;
    bool m_showRectified = true;
    cv::Size m_boardSize;
    float m_squareSize;
    std::vector<std::string> m_imagelist;
};

#endif // WIDGETCALIBRATION_H