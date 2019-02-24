#ifndef WIDGETCHECKBOARDINFORMATION_H
#define WIDGETCHECKBOARDINFORMATION_H

#include <QWidget>

namespace Ui {
class WidgetCheckboardInformation;
}

class WidgetCheckboardInformation : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetCheckboardInformation(QWidget *parent = nullptr);
    ~WidgetCheckboardInformation();

private:
    Ui::WidgetCheckboardInformation *ui;
};

#endif // WIDGETCHECKBOARDINFORMATION_H
