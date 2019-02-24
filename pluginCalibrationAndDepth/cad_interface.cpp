#include "cad_interface.h"
#include "widgetcalibration.h"
#include "widgetdepthmap.h"
#include "widgetfilemodecalibration.h"
#include "widgetcalibrationmode.h"
QString CAD_Interface::m_pluginName = "pluginCalibrationAndDepth";

CAD_Interface::CAD_Interface(QObject *parent) :
    QObject(parent)
{
    m_widgetCalibration = new WidgetCalibration();
    m_widgetDepthMap = new WidgetDepthMap();
    m_widgetFilemodeCalibration = new WidgetFilemodeCalibration();
    m_widgetCalibrationMode = new WidgetCalibrationMode;

    //тут будут connect между виджетами
}

CAD_Interface::~CAD_Interface()
{
    delete m_widgetCalibration;
    delete m_widgetDepthMap;
    delete m_widgetFilemodeCalibration;
    delete m_widgetCalibrationMode;
}

const QString &CAD_Interface::pluginName() const
{
    return m_pluginName;
}

QWidget *CAD_Interface::showSettingsWidgetCalibration()
{
    return m_widgetCalibration;
}

QWidget *CAD_Interface::showSettingsWidgetCalibrationMode()
{
    return m_widgetCalibrationMode;
}

QWidget *CAD_Interface::showSettingsWidgetFilemodeCalibration()
{
    return m_widgetFilemodeCalibration;
}

QWidget *CAD_Interface::showSettingsWidgetDepthMap()
{
    return m_widgetDepthMap;
}
