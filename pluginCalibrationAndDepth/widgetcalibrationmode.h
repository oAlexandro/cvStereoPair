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

private:
    Ui::WidgetCalibrationMode *ui;
};

#endif // WIDGETCALIBRATIONMODE_H
