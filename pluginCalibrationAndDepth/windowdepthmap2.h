#ifndef WINDOWDEPTHMAP2_H
#define WINDOWDEPTHMAP2_H

#include <QWidget>
#include<QBoxLayout>
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include<QLabel>
namespace Ui {
class windowdepthmap2;
}

class windowdepthmap2 : public QWidget
{
    Q_OBJECT

public:
    QLabel* m_outputImageLable = nullptr;
    explicit windowdepthmap2(QWidget *parent = nullptr);
    ~windowdepthmap2();
    void resizeEvent(QResizeEvent *event);

signals:
   void Number(int& n_1,int& n_2,
               int& n_3,int& n_4,
               int& n_5,int& n_6,
               int& n_7,int& n_8,
               int& n_9,int& n_10,
               bool& insinuation);
   void NewOptions();

public slots:
   void OpenWindow();
   void OpenPicture(cv::Mat a);

private slots:


   void on_b_setImage_clicked();
   void on_spinBox_valueChanged(int arg1);
   void on_spinBox_2_valueChanged(int arg1);
   void on_spinBox_3_valueChanged(float arg1);
   void on_spinBox_4_valueChanged(int arg1);
   void on_spinBox_5_valueChanged(int arg1);
   void on_spinBox_6_valueChanged(int arg1);
   void on_spinBox_7_valueChanged(int arg1);
   void on_spinBox_8_valueChanged(int arg1);
   void on_spinBox_9_valueChanged(int arg1);
   void on_spinBox_10_valueChanged(int arg1);
   void on_radioButton_clicked(bool checked);
   void on_pushButton_clicked();

private:
    int parametr_1,parametr_2,parametr_3,
        parametr_4,parametr_5,parametr_6,
        parametr_7,parametr_8,parametr_9,
        parametr_10;
   bool paramet=false;
    Ui::windowdepthmap2 *ui;
    cv::Mat m_img1;
};

#endif // WINDOWDEPTHMAP2_H
