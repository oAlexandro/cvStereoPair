#include "widgetfilemodecalibration.h"
#include "ui_widgetfilemodecalibration.h"

WidgetFilemodeCalibration::WidgetFilemodeCalibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetFilemodeCalibration)
{
    ui->setupUi(this);
}

WidgetFilemodeCalibration::~WidgetFilemodeCalibration()
{
    delete ui;
}
