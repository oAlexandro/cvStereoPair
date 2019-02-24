#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPluginLoader>
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QVBoxLayout>
#include <QThread>
#include <QMutex>

class PluginInterface;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel* m_inputCamera1 = nullptr;
    QLabel* m_inputCamera2 = nullptr;
    QLabel* m_outputCamera1 = nullptr;
    QLabel* m_outputCamera2 = nullptr;
    PluginInterface* m_interface = nullptr;
};

#endif // MAINWINDOW_H
