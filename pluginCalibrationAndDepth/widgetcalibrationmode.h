#ifndef WIDGETCALIBRATIONMODE_H
#define WIDGETCALIBRATIONMODE_H

#include <QWidget>

namespace Ui {
class WidgetCalibrationMode;
}

class WidgetCalibrationMode : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetCalibrationMode(QWidget *parent = nullptr);
    ~WidgetCalibrationMode();

private slots:
    void on_rb_realtimemode_clicked();

    void on_rb_filemode_clicked();

signals:
    void onRealtimeMode();
    void stopCamera();

private:
    Ui::WidgetCalibrationMode *ui;
};

#endif // WIDGETCALIBRATIONMODE_H
