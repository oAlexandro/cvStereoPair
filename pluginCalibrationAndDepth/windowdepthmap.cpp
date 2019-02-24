#include "windowdepthmap.h"
#include "ui_windowdepthmap.h"

WindowDepthMap::WindowDepthMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowDepthMap)
{
    ui->setupUi(this);
}

WindowDepthMap::~WindowDepthMap()
{
    delete ui;
}
