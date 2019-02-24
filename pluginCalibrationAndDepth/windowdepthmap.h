#ifndef WINDOWDEPTHMAP_H
#define WINDOWDEPTHMAP_H

#include <QWidget>

namespace Ui {
class WindowDepthMap;
}

class WindowDepthMap : public QWidget
{
    Q_OBJECT

public:
    explicit WindowDepthMap(QWidget *parent = nullptr);
    ~WindowDepthMap();

private:
    Ui::WindowDepthMap *ui;
};

#endif // WINDOWDEPTHMAP_H
