#include "cad_interface.h"
#include "widgetcalibration.h"
#include "widgetdepthmap.h"
#include "widgetfilemodecalibration.h"
#include "widgetcalibrationmode.h"
#include "widgetcheckboardinformation.h"
#include "widgetstatus.h"
#include "windowdepthmap2.h"
#include "widgetleftinput.h"
#include "widgetleftoutput.h"
#include "widgetrightoutput.h"
#include "widgetrightinput.h"
#include "calibrationprocess.h"
#include "camera.h"
#include "widgetrealtimecalibration.h"

QString CAD_Interface::m_pluginName = "pluginCalibrationAndDepth";

CAD_Interface::CAD_Interface(QObject *parent) :
    QObject(parent)
{
    m_widgetCalibration = new WidgetCalibration();
    m_widgetDepthMap = new WidgetDepthMap();
    m_widgetFilemodeCalibration = new WidgetFilemodeCalibration();
    m_widgetCalibrationMode = new WidgetCalibrationMode;
    m_widgetCheckboardInformation = new WidgetCheckboardInformation();
    m_widgetStatus = new WidgetStatus();
    m_WindowDepthMap=new windowdepthmap2();
    m_widgetLeftInput = new WidgetLeftInput();
    m_widgetLeftOutput = new WidgetLeftOutput();
    m_widgetRightOutput = new WidgetRightOutput();
    m_widgetRightInput = new WidgetRightInput();
    m_calibrationProcess = new CalibrationProcess();
    m_camera = new Camera();
    m_widgetRealtimeCalibration = new WidgetRealTimeCalibration();

    connect(m_calibrationProcess,&CalibrationProcess::sendStrToStatus,m_widgetStatus,&WidgetStatus::getText);//добавление нового оповещения в статус
    connect(m_widgetCalibration,&WidgetCalibration::sendStrToStatus,m_widgetStatus,&WidgetStatus::getText);
    connect(m_camera,&Camera::sendStrToStatus,m_widgetStatus,&WidgetStatus::getText);
    //сигнал с слайдера windowdepthmap
    //тут будут connect между виджетами
    connect(m_widgetFilemodeCalibration,&WidgetFilemodeCalibration::sendVectorString,m_widgetCalibration,&WidgetCalibration::getImagelist); // отправка изображений на обработку

    connect(m_calibrationProcess,&CalibrationProcess::signalForTestDepthMap,m_widgetDepthMap,&WidgetDepthMap::depthMapping); //test
    connect(m_widgetDepthMap,&WidgetDepthMap::sendStartSignal,m_WindowDepthMap,&windowdepthmap2::OpenWindow);
    connect(m_widgetDepthMap,&WidgetDepthMap::picture,m_WindowDepthMap,&windowdepthmap2::OpenPicture);

    //connect(m_widgetCalibration,&WidgetCalibration::signalForTestDepthMap,m_widgetDepthMap,&WidgetDepthMap::depthMapping); //test
    connect(m_calibrationProcess,&CalibrationProcess::signalForInputLeft,m_widgetLeftInput,&WidgetLeftInput::showImage);
    connect(m_calibrationProcess,&CalibrationProcess::signalForOutput,m_widgetLeftOutput,&WidgetLeftOutput::showImage);
    connect(m_calibrationProcess,&CalibrationProcess::signalForOutputRight,m_widgetRightOutput,&WidgetRightOutput::showImage);
    connect(m_calibrationProcess,&CalibrationProcess::signalForInputRight,m_widgetRightInput,&WidgetRightInput::showImage);
    connect(m_widgetCalibration,&WidgetCalibration::startCalibration,m_calibrationProcess,&CalibrationProcess::stereoCalibration);

    connect(m_widgetFilemodeCalibration,&WidgetFilemodeCalibration::sendVectorToStartLeft,m_widgetLeftInput,&WidgetLeftInput::showImage);
    connect(m_widgetFilemodeCalibration,&WidgetFilemodeCalibration::sendVectorToStartRight,m_widgetRightInput,&WidgetRightInput::showImage);

    connect(m_widgetCalibrationMode,&WidgetCalibrationMode::stopCamera,m_camera,&Camera::stopTimer);
    connect(m_widgetCalibrationMode,&WidgetCalibrationMode::onRealtimeMode,m_camera,&Camera::startTimer);
    connect(m_camera,&Camera::sendFrameToLeftInput,m_widgetLeftInput,&WidgetLeftInput::showImage);
    connect(m_camera,&Camera::sendFrameToRightInput,m_widgetRightInput,&WidgetRightInput::showImage);
    connect(m_widgetRealtimeCalibration,&WidgetRealTimeCalibration::sendSaveDir,m_camera,&Camera::getDir);
    connect(m_widgetRealtimeCalibration,&WidgetRealTimeCalibration::getManualFrame,m_camera,&Camera::manualFrame);
    connect(m_camera,&Camera::sendFrameToLeftOutput,m_widgetLeftOutput,&WidgetLeftOutput::showImage);
    connect(m_camera,&Camera::sendFrameToRightOutput,m_widgetRightOutput,&WidgetRightOutput::showImage);

    connect(m_widgetRealtimeCalibration,&WidgetRealTimeCalibration::getAutoFrame,m_camera,&Camera::autoFrame);

    connect(m_camera,&Camera::sendFramesToDetection,m_calibrationProcess,&CalibrationProcess::getAutoFrameDetection);
    connect(m_calibrationProcess,&CalibrationProcess::sendForSaveFrames,m_camera,&Camera::saveFrames);

}

CAD_Interface::~CAD_Interface()
{
    delete m_widgetCalibration;
    delete m_widgetDepthMap;
    delete m_widgetFilemodeCalibration;
    delete m_widgetCalibrationMode;
    delete m_WindowDepthMap;
    delete m_widgetCheckboardInformation;
    delete m_widgetStatus;
    delete m_widgetLeftInput;
    delete m_widgetLeftOutput;
    delete m_widgetRightOutput;
    delete m_widgetRightInput;
    delete m_camera;
    delete m_widgetRealtimeCalibration;
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

QWidget *CAD_Interface::showSettingsWidgetCheckboardInformation()
{
    return m_widgetCheckboardInformation;
}

QWidget *CAD_Interface::showSettingsWidgetStatus()
{
    return m_widgetStatus;
}

QWidget *CAD_Interface::showLeftInputImage()
{
    return m_widgetLeftInput;
}

QWidget *CAD_Interface::showLeftOutputImage()
{
    return m_widgetLeftOutput;
}

QWidget *CAD_Interface::showRightOutputImage()
{
    return m_widgetRightOutput;
}

QWidget *CAD_Interface::showRightInputImage()
{
    return m_widgetRightInput;
}

QWidget *CAD_Interface::showSettingsWidgetRealtimeCalibration()
{
    return m_widgetRealtimeCalibration;
}
