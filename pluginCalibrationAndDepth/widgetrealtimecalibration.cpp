#include "widgetrealtimecalibration.h"
#include "ui_widgetrealtimecalibration.h"
#include <QFileDialog>

WidgetRealTimeCalibration::WidgetRealTimeCalibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetRealTimeCalibration)
{
    ui->setupUi(this);
}

WidgetRealTimeCalibration::~WidgetRealTimeCalibration()
{
    delete ui;
}

void WidgetRealTimeCalibration::on_b_manual_clicked()
{
    emit getManualFrame();
}

void WidgetRealTimeCalibration::on_b_saveDir_clicked()
{
    QString directoryName = QFileDialog::getExistingDirectory(this,
                                                              tr("Open Directory"), "/home",
                                                              QFileDialog::ShowDirsOnly
                                                              | QFileDialog::DontResolveSymlinks);
    if(!directoryName.isEmpty()){
        emit sendSaveDir(directoryName);
    }
}

//void WidgetRealTimeCalibration::on_b_auto_clicked()
//{

//}

void WidgetRealTimeCalibration::on_b_auto_released()
{
    emit getAutoFrame();
}
