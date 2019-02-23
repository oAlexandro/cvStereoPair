#ifndef WIDGETCALIBRATION_H
#define WIDGETCALIBRATION_H

#include <QWidget>

namespace Ui {
class widgetCalibration;
}

class widgetCalibration : public QWidget
{
    Q_OBJECT

public:
    explicit widgetCalibration(QWidget *parent = nullptr);
    ~widgetCalibration();

private:
    Ui::widgetCalibration *ui;
};

#endif // WIDGETCALIBRATION_H
