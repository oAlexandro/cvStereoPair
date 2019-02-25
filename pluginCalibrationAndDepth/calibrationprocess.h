#ifndef CALIBRATIONPROCESS_H
#define CALIBRATIONPROCESS_H

#include <QObject>
#include <QThread>
#include <QMutex>

class CalibrationProcess : public QObject
{
    Q_OBJECT
public:
    explicit CalibrationProcess(QObject *parent = nullptr);
    ~CalibrationProcess();

signals:

public slots:

private:
    QThread m_thread;
    QMutex m_mutex;
};

#endif // CALIBRATIONPROCESS_H
