#ifndef WIDGETDEPTHMAP_H
#define WIDGETDEPTHMAP_H

#include <QWidget>

namespace Ui {
class WidgetDepthMap;
}

class WidgetDepthMap : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetDepthMap(QWidget *parent = nullptr);
    ~WidgetDepthMap();

private:
    Ui::WidgetDepthMap *ui;
};

#endif // WIDGETDEPTHMAP_H
