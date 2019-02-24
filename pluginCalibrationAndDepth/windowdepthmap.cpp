#include "windowdepthmap.h"
#include "ui_windowdepthmap.h"


WindowDepthMap::WindowDepthMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowDepthMap)
{
    ui->setupUi(this);


    connect(ui->spinBox, SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)) );
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->spinBox,SLOT(setValue(int)) );
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),ui->horizontalSlider_2,SLOT(setValue(int)) );
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),ui->spinBox_2,SLOT(setValue(int)) );

}

WindowDepthMap::~WindowDepthMap()
{
    delete ui;
}

void WindowDepthMap::on_horizontalSlider_actionTriggered(int action)
{
   emit Number(action);
}
