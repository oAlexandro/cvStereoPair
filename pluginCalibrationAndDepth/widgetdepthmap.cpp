#include "widgetdepthmap.h"
#include "ui_widgetdepthmap.h"

WidgetDepthMap::WidgetDepthMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetDepthMap)
{
    ui->setupUi(this);
}

WidgetDepthMap::~WidgetDepthMap()
{
    delete ui;
}
