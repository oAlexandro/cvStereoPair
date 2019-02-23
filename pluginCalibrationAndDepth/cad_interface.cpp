#include "cad_interface.h"
#include "widgetcalibration.h"
#include "widgetdepthmap.h"
QString CAD_Interface::m_pluginName = "pluginCalibrationAndDepth";

CAD_Interface::CAD_Interface(QObject *parent) :
    QObject(parent)
{
    m_widgetCalibration = new WidgetCalibration();
    m_widgetDepthMap = new WidgetDepthMap();
}

CAD_Interface::~CAD_Interface()
{
    delete m_widgetCalibration;
    delete m_widgetDepthMap;
}

const QString &CAD_Interface::pluginName() const
{
    return m_pluginName;
}

QWidget *CAD_Interface::showSettingsWidgetCalibration()
{
    return m_widgetCalibration;
}
