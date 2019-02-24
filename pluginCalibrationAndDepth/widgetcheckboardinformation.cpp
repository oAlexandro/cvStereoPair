#include "widgetcheckboardinformation.h"
#include "ui_widgetcheckboardinformation.h"

WidgetCheckboardInformation::WidgetCheckboardInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetCheckboardInformation)
{
    ui->setupUi(this);
}

WidgetCheckboardInformation::~WidgetCheckboardInformation()
{
    delete ui;
}
