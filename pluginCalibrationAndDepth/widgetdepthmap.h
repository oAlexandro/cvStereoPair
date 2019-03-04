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
    void depthMapOptions(int &number_1,int &number_2,int &number_3,
                         int &number_4,int &number_5,int &number_6,
                         int &number_7,int &number_8,int &number_9,
                         int &number_10,bool &insinuation);



private slots:
    void on_b_startDepthMap_clicked();
    void on_b_settingsDepthMap_clicked();
    void on_b_updateSet_clicked();

private:
    Ui::WidgetDepthMap *ui;
    cv::Mat m_sendImg;
    cv::Mat image_left,image_right;
    int parametr_1,parametr_2,parametr_3,
        parametr_4,parametr_5,parametr_6,
        parametr_7,parametr_8,parametr_9,
        parametr_10;
   bool paramet;
};

#endif // WIDGETDEPTHMAP_H
