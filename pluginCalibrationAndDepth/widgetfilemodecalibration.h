#ifndef WIDGETFILEMODECALIBRATION_H
#define WIDGETFILEMODECALIBRATION_H

#include <QWidget>

namespace Ui {
class WidgetFilemodeCalibration;
}

class WidgetFilemodeCalibration : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFilemodeCalibration(QWidget *parent = nullptr);
    ~WidgetFilemodeCalibration();

private:
    Ui::WidgetFilemodeCalibration *ui;
};

#endif // WIDGETFILEMODECALIBRATION_H
