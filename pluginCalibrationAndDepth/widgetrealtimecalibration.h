#ifndef WIDGETREALTIMECALIBRATION_H
#define WIDGETREALTIMECALIBRATION_H

#include <QWidget>

namespace Ui {
class WidgetRealTimeCalibration;
}

class WidgetRealTimeCalibration : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetRealTimeCalibration(QWidget *parent = nullptr);
    ~WidgetRealTimeCalibration();

private slots:
    void on_b_manual_clicked();

    void on_b_saveDir_clicked();

    //void on_b_auto_clicked();

    void on_b_auto_released();

signals:
    void getManualFrame();
    void sendSaveDir(QString);
    void getAutoFrame();

private:
    Ui::WidgetRealTimeCalibration *ui;
};

#endif // WIDGETREALTIMECALIBRATION_H
