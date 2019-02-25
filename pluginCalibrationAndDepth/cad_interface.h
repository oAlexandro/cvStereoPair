#ifndef CAD_INTERFACE_H
#define CAD_INTERFACE_H

#include <QObject>
#include "../pluginInterface/plugininterface.h"
#include <opencv2/core.hpp>

class WidgetCalibration;
class WidgetDepthMap;
class WidgetFilemodeCalibration;
class WidgetCalibrationMode;
class WidgetCheckboardInformation;
class WidgetStatus;
class windowdepthmap2;

class CAD_Interface : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "pluginCalibrationAndDepth.json")
    Q_INTERFACES(PluginInterface)

public:
    CAD_Interface(QObject *parent = nullptr);
    ~CAD_Interface();
    virtual const QString& pluginName() const;
    virtual QWidget* showSettingsWidgetCalibration();
    virtual QWidget* showSettingsWidgetCalibrationMode();
    virtual QWidget* showSettingsWidgetFilemodeCalibration();
    virtual QWidget* showSettingsWidgetDepthMap();
    virtual QWidget* showSettingsWidgetCheckboardInformation();
    virtual QWidget* showSettingsWidgetStatus();



signals:

public slots:

private:
    WidgetCalibration* m_widgetCalibration = nullptr;
    WidgetDepthMap* m_widgetDepthMap = nullptr;
    WidgetFilemodeCalibration* m_widgetFilemodeCalibration = nullptr;
    WidgetCalibrationMode* m_widgetCalibrationMode = nullptr;
    WidgetCheckboardInformation* m_widgetCheckboardInformation = nullptr;
    WidgetStatus* m_widgetStatus = nullptr;
    static QString m_pluginName;
    windowdepthmap2* m_WindowDepthMap =nullptr;

};

#endif // CAD_INTERFACE_H
