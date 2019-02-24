#ifndef WINDOWDEPTHMAP_H
#define WINDOWDEPTHMAP_H

#include <QDialog>

namespace Ui {
class WindowDepthMap;
}

class WindowDepthMap : public QDialog
{
    Q_OBJECT

public:
    explicit WindowDepthMap(QWidget *parent = nullptr);
    ~WindowDepthMap();

private:
    Ui::WindowDepthMap *ui;
};

#endif // WINDOWDEPTHMAP_H
