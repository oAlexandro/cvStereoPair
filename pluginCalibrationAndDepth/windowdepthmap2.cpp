#include "windowdepthmap2.h"
#include "ui_windowdepthmap2.h"
#include"Windows.h"
#include"QDebug"

windowdepthmap2::windowdepthmap2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::windowdepthmap2)
{
    ui->setupUi(this);
    m_outputImageLable = ui->outVideoImage_DepthMap;
    connect(ui->spinBox, SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)) );
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->spinBox,SLOT(setValue(int)) );
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),ui->horizontalSlider_2,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),ui->spinBox_2,SLOT(setValue(int)) );
    connect(ui->spinBox_3, SIGNAL(valueChanged(int)),ui->horizontalSlider_3,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),ui->spinBox_3,SLOT(setValue(int)) );
    connect(ui->spinBox_4, SIGNAL(valueChanged(int)),ui->horizontalSlider_4,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),ui->spinBox_4,SLOT(setValue(int)) );
    connect(ui->spinBox_5, SIGNAL(valueChanged(int)),ui->horizontalSlider_5,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_5,SIGNAL(valueChanged(int)),ui->spinBox_5,SLOT(setValue(int)) );
    connect(ui->spinBox_6, SIGNAL(valueChanged(int)),ui->horizontalSlider_6,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_6,SIGNAL(valueChanged(int)),ui->spinBox_6,SLOT(setValue(int)) );
    connect(ui->spinBox_7, SIGNAL(valueChanged(int)),ui->horizontalSlider_7,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_7,SIGNAL(valueChanged(int)),ui->spinBox_7,SLOT(setValue(int)) );
    connect(ui->spinBox_8, SIGNAL(valueChanged(int)),ui->horizontalSlider_8,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_8,SIGNAL(valueChanged(int)),ui->spinBox_8,SLOT(setValue(int)) );
    connect(ui->spinBox_9, SIGNAL(valueChanged(int)),ui->horizontalSlider_9,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_9,SIGNAL(valueChanged(int)),ui->spinBox_9,SLOT(setValue(int)) );
    connect(ui->spinBox_10, SIGNAL(valueChanged(int)),ui->horizontalSlider_10,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_10,SIGNAL(valueChanged(int)),ui->spinBox_10,SLOT(setValue(int)) );

}
windowdepthmap2::~windowdepthmap2()
{
    delete ui;
}

void windowdepthmap2::OpenWindow()
{
    this->show();
}

void windowdepthmap2::OpenPicture(cv::Mat _image)
{
    m_img1 = _image;
    QImage m_testImage;
    if(_image.channels()== 3){
        m_testImage = QImage(_image.data,_image.cols,_image.rows,static_cast<int>(_image.step),QImage::Format_RGB888);
    }
    else{
        m_testImage = QImage(_image.data, _image.cols,_image.rows, static_cast<int>(_image.step),QImage::Format_Indexed8);
    }
    if (!m_testImage.isNull()){
        m_outputImageLable->setAlignment(Qt::AlignCenter);
        m_outputImageLable->setPixmap(QPixmap::fromImage(m_testImage).scaled(m_outputImageLable->size(),
                                                                             Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }
}

void windowdepthmap2::resizeEvent(QResizeEvent *event)
{
    if(event)
    {
        if(!(ui->outVideoImage_DepthMap->text()=="Image not found."))
            OpenPicture(m_img1);
    }
}
void windowdepthmap2::on_spinBox_valueChanged(int arg1)
{
      parametr_1=arg1;
}

void windowdepthmap2::on_spinBox_2_valueChanged(int arg1)
{
  if(arg1%16==0&&arg1!=0)
  {
  parametr_2=arg1;
  qDebug()<<parametr_2;
  }
}

void windowdepthmap2::on_spinBox_3_valueChanged(float arg1)
{
//   if(!arg1%2==0)
//   {
    parametr_3=arg1;
    qDebug()<<parametr_3;
//   }
}

void windowdepthmap2::on_spinBox_4_valueChanged(int arg1)
{
    parametr_4=arg1;
}

void windowdepthmap2::on_spinBox_5_valueChanged(int arg1)
{
    parametr_5=arg1;
}

void windowdepthmap2::on_spinBox_6_valueChanged(int arg1)
{
    parametr_6=arg1;
}

void windowdepthmap2::on_spinBox_7_valueChanged(int arg1)
{
    parametr_7=arg1;
}

void windowdepthmap2::on_spinBox_8_valueChanged(int arg1)
{
    parametr_8=arg1;
}

void windowdepthmap2::on_spinBox_9_valueChanged(int arg1)
{
    parametr_9=arg1;
}

void windowdepthmap2::on_spinBox_10_valueChanged(int arg1)
{
    parametr_10=arg1;
}

void windowdepthmap2::on_radioButton_clicked(bool checked)
{
    paramet=checked;
}
void windowdepthmap2::on_b_setImage_clicked()
{
    emit Number(parametr_1,parametr_2,parametr_3,
                parametr_4,parametr_5,parametr_6,
                parametr_7,parametr_8,parametr_9,
                parametr_10,paramet);
    emit NewOptions();
}

void windowdepthmap2::on_pushButton_clicked()
{
    parametr_1=-64;
    ui->spinBox->setValue(-64);
    parametr_2=192;
    ui->spinBox_2->setValue(192);
    parametr_3=5;
    ui->spinBox_3->setValue(5);
    parametr_4=600;
    ui->spinBox_4->setValue(600);
    parametr_5=2400;
    ui->spinBox_5->setValue(2400);
    parametr_6=10;
    ui->spinBox_6->setValue(10);
    parametr_7=4;
    ui->spinBox_7->setValue(4);
    parametr_8=1;
    ui->spinBox_8->setValue(1);
    parametr_9=150;
    ui->spinBox_9->setValue(150);
    parametr_10=2;
    ui->spinBox_10->setValue(2);
    paramet=false;
}
