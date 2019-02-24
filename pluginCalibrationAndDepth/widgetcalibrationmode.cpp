#include "widgetcalibrationmode.h"
#include "ui_widgetcalibrationmode.h"

WidgetCalibrationMode::WidgetCalibrationMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetCalibrationMode)
{
    ui->setupUi(this);
}

WidgetCalibrationMode::~WidgetCalibrationMode()
{
    delete ui;
}
