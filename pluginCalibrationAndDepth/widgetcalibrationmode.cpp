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

void WidgetCalibrationMode::on_rb_realtimemode_clicked()
{
    emit onRealtimeMode();
}

void WidgetCalibrationMode::on_rb_filemode_clicked()
{
    emit stopCamera();
}
