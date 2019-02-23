#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../pluginInterface/plugininterface.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    QVBoxLayout* myVBox = new QVBoxLayout();
    if(m_interface){
        myVBox->addWidget(m_interface->showSettingsWidgetCalibration());
//        myVBox->addWidget(m_interface->showSettingsWidgetPAN());
//        myVBox->addWidget(m_interface->showSettingsWidgetProcessing());             блок для добавления виджетов
//        myVBox->addWidget(m_interface->showSettingsWidgetSave());
//        myVBox->addWidget(m_interface->showSettingsWidgetStart());
    }
    ui->layout_calibControl->addLayout(myVBox);

}

MainWindow::~MainWindow()
{
    if(m_interface)
        delete m_interface;
    delete ui;
}
