#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H
#include <QtPlugin>

class PluginInterface
{
public:
    PluginInterface(){}
    virtual ~PluginInterface(){}
    virtual const QString& pluginName() const = 0;
    virtual QWidget* showSettingsWidgetCalibration() = 0;
    virtual QWidget* showSettingsWidgetCalibrationMode() = 0;
    virtual QWidget* showSettingsWidgetFilemodeCalibration() = 0;
    virtual QWidget* showSettingsWidgetDepthMap() = 0;
    virtual QWidget* showSettingsWidgetCheckboardInformation() = 0;
    virtual QWidget* showSettingsWidgetStatus() = 0;
};

QT_BEGIN_NAMESPACE

#define PluginInterface_iid "PrepareDeepLearning.PluginInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
QT_END_NAMESPACE


#endif // PLUGININTERFACE_H
