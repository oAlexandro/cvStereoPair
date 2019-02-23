#include "widgetcalibration.h"
#include "ui_widgetcalibration.h"

widgetCalibration::widgetCalibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetCalibration)
{
    ui->setupUi(this);
}

widgetCalibration::~widgetCalibration()
{
    delete ui;
}
