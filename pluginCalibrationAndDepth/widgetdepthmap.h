#ifndef WIDGETDEPTHMAP_H
#define WIDGETDEPTHMAP_H

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
class WidgetDepthMap;
}

class WidgetDepthMap : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetDepthMap(QWidget *parent = nullptr);
    ~WidgetDepthMap();
signals:
    void picture(cv::Mat s);
    void sendStartSignal();
    void sendImageToWindow(cv::Mat resDepthMap);

public slots:
    void depthMapping();
    void Image(cv::Mat img_left,cv::Mat img_right);
    void saveXYZ(const char* filename, const cv::Mat& mat);
    void depthMapOptions(int number,int number_2);



private slots:
    void on_b_startDepthMap_clicked();
    void on_b_settingsDepthMap_clicked();
    void on_b_updateSet_clicked();

private:
    Ui::WidgetDepthMap *ui;
    cv::Mat m_sendImg;
    cv::Mat image_left,image_right;
    int par_1,par_2;
};

#endif // WIDGETDEPTHMAP_H
