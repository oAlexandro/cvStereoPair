#include "widgetstatus.h"
#include "ui_widgetstatus.h"
#include <QDebug>
WidgetStatus::WidgetStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetStatus)
{
    ui->setupUi(this);
//    model->insertRow(model->rowCount());
//    QModelIndex index = model->index(model->rowCount()-1)
//    model->setData(index, str);
//    QString str = "hello";
//    for(int i = 0; i < 30; i++){
//        ui->textBrowser->append(str);
//    }
}

WidgetStatus::~WidgetStatus()
{
    delete ui;
}

void WidgetStatus::getText(QString str)
{
    //m_str = str;
    //qDebug()<<"he";
    ui->textBrowser->append(str);
}
