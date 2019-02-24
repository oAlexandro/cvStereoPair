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
signals:
   void Number(int n);
private slots:
    void on_horizontalSlider_actionTriggered(int action);

private:
    Ui::WindowDepthMap *ui;
};

#endif // WINDOWDEPTHMAP_H
