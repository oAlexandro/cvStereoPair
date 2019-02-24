#include "widgetrightoutput.h"
#include "ui_widgetrightoutput.h"

WidgetRightOutput::WidgetRightOutput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetRightOutput)
{
    ui->setupUi(this);
}

WidgetRightOutput::~WidgetRightOutput()
{
    delete ui;
}

void WidgetRightOutput::showImage(cv::Mat img1)
{
    QImage leftInput;
    QPixmap leftPixmap;
    //QImage leftInput = QImage(img1.data,img1.cols,img1.rows,static_cast<int>(img1.step),QImage::Format_RGB888);
    if(img1.channels() == 3) {
            leftInput = QImage(img1.data,img1.cols,img1.rows,static_cast<int>(img1.step),QImage::Format_RGB888);
        } else {
            leftInput = QImage(img1.data, img1.cols,img1.rows, static_cast<int>(img1.step),QImage::Format_Indexed8);
        }
    if (!leftInput.isNull()) {
        leftPixmap = QPixmap::fromImage(leftInput);
        ui->labelOutput->setAlignment(Qt::AlignCenter);
        ui->labelOutput->setPixmap(leftPixmap.scaled(ui->labelOutput->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
       }
}
