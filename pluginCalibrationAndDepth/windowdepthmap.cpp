#include "windowdepthmap.h"
#include "ui_windowdepthmap.h"

WindowDepthMap::WindowDepthMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowDepthMap)
{
    ui->setupUi(this);
}

WindowDepthMap::~WindowDepthMap()
{
    delete ui;
}
