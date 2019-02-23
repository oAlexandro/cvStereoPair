#ifndef CAD_INTERFACE_H
#define CAD_INTERFACE_H

#include <QObject>

class CAD_Interface : public QObject
{
    Q_OBJECT
public:
    explicit CAD_Interface(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CAD_INTERFACE_H