#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../pluginInterface/plugininterface.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_inputCamera1 = ui->outVideoImage_inputCamera1;
    m_inputCamera2 = ui->outVideoImage_inputCamera2;
    m_outputCamera1 = ui->outVideoImage_outputCamera1;
    m_outputCamera2 = ui->outVideoImage_outputCamera2;

    QDir pluginsDir(qApp->applicationDirPath());
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();

        if (plugin) {
            m_interface = qobject_cast<PluginInterface *>(plugin);
            if (m_interface){
                qDebug()<<m_interface->pluginName();

            }
        }
    }

    QVBoxLayout* vbox_calibControl = new QVBoxLayout();
    QVBoxLayout* vbox_filemodeCalib = new QVBoxLayout();
    QVBoxLayout* vbox_selectCalibMode = new QVBoxLayout();
    QVBoxLayout* vbox_depthMap = new QVBoxLayout();
    if(m_interface){
        vbox_calibControl->addWidget(m_interface->showSettingsWidgetCalibration());
        vbox_filemodeCalib->addWidget(m_interface->showSettingsWidgetFilemodeCalibration());
        vbox_selectCalibMode->addWidget(m_interface->showSettingsWidgetCalibrationMode());
        vbox_depthMap->addWidget(m_interface->showSettingsWidgetDepthMap());
//        myVBox->addWidget(m_interface->showSettingsWidgetProcessing());             блок для добавления виджетов
//        myVBox->addWidget(m_interface->showSettingsWidgetSave());
//        myVBox->addWidget(m_interface->showSettingsWidgetStart());
    }
    ui->layout_calibControl->addLayout(vbox_calibControl);
    ui->layout_filemodeCalib->addLayout(vbox_filemodeCalib);
    ui->layout_selectCalibMode->addLayout(vbox_selectCalibMode);
    ui->layout_depthMap->addLayout(vbox_depthMap);

}

MainWindow::~MainWindow()
{
    if(m_interface)
        delete m_interface;
    delete ui;
}