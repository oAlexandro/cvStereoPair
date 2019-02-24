#ifndef WIDGETSTATUS_H
#define WIDGETSTATUS_H

#include <QWidget>

namespace Ui {
class WidgetStatus;
}

class WidgetStatus : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetStatus(QWidget *parent = nullptr);
    ~WidgetStatus();

public slots:
    void getText(QString str);
private:
    Ui::WidgetStatus *ui;
    QString m_str;
};

#endif // WIDGETSTATUS_H
