#include "setupviewmgr.h"

SetupViewMgr::SetupViewMgr(QObject *parent,
                           Instrument &instrument,
                           Settings &settings,
                           SetupTab &setuptab) : QObject(parent),
    m_instrument(instrument),
    m_setuptab(setuptab)
{
    WireSettings(settings);
    settings.ParseJsonData();
    WireHostAndPort();
    WireMessages();
    WireButtons();
    WireDisplayUpdate();

    m_setuptab.SetHostName(settings.getHostName());
    m_setuptab.SetPort(settings.getPortNumber());
    m_setuptab.SetCommands(settings.getCommandsAsModel());
    auto long_wait = settings.getLongWaitMs();
    auto short_wait = settings.getShortWaitMs();
    m_instrument.SetLongWaitMs(long_wait);
    m_instrument.SetShortWaitMs(short_wait);
    emit NotifyStatusUpdated(QString("Long Wait Ms: %1").arg(long_wait));
    emit NotifyStatusUpdated(QString("Short Wait Ms: %1").arg(short_wait));
    onDisconnected();
}

void SetupViewMgr::onConnected()
{
    emit NotifyConnectEnabled(false);
    emit NotifyDisConnectEnabled(true);
    emit NotifyDirectCommandsEnabled(true);
    emit NotifyControlTabEnabled(true);
}

void SetupViewMgr::onDisconnected()
{
    emit NotifyConnectEnabled(true);
    emit NotifyDisConnectEnabled(false);
    emit NotifyDirectCommandsEnabled(false);
    emit NotifyControlTabEnabled(false);
}

SetupViewMgr::~SetupViewMgr()
{
    Utils::DestructorMsg(this);
}

void SetupViewMgr::WireSettings(Settings &config){

    connect(&config, &Settings::NotifyStatusMessage,
            &m_setuptab, &SetupTab::onStatusUpdated);
}


void SetupViewMgr::WireHostAndPort(){

    connect(&m_setuptab, &SetupTab::NotifyHostNameChanged,
            &m_instrument, &Instrument::onHostNameChanged);
    connect(&m_setuptab, &SetupTab::NotifyPortChanged,
            &m_instrument, &Instrument::onPortChanged);
}


void SetupViewMgr::WireButtons(){

    connect(&m_setuptab, &SetupTab::NotifyConnectClicked,
            &m_instrument, &Instrument::Connect);
    connect(&m_instrument, &Instrument::NotifyConnected,
             &m_setuptab, &SetupTab::onConnected);
    connect(&m_instrument, &Instrument::NotifyConnected,
             this, &SetupViewMgr::onConnected);

    connect(&m_setuptab, &SetupTab::NotifyDisconnectClicked,
            &m_instrument, &Instrument::Disconnect);
    connect(&m_instrument, &Instrument::NotifyDisconnected,
             &m_setuptab, &SetupTab::onDisconnected);
    connect(&m_instrument, &Instrument::NotifyDisconnected,
             this, &SetupViewMgr::onDisconnected);

    connect(&m_setuptab, &SetupTab::NotifySendClicked,
            &m_instrument, &Instrument::onSendRequest);
    connect(&m_setuptab, &SetupTab::NotifyReceiveClicked,
             &m_instrument, &Instrument::onReceiveRequest);
    connect(&m_instrument, &Instrument::NotifyDataReceived,
             &m_setuptab, &SetupTab::onDataReceived);
    connect(&m_instrument, &Instrument::NotifyDataSent,
             &m_setuptab, &SetupTab::onDataSent);

}

void SetupViewMgr::WireDisplayUpdate()
{
    connect(this, &SetupViewMgr::NotifyConnectEnabled,
             &m_setuptab, &SetupTab::onConnectEnabled);
    connect(this, &SetupViewMgr::NotifyDisConnectEnabled,
             &m_setuptab, &SetupTab::onDisconnectEnabled);
    connect(this, &SetupViewMgr::NotifyDirectCommandsEnabled,
             &m_setuptab, &SetupTab::onDirectCommandsEnabled);
    connect(this, &SetupViewMgr::NotifyControlTabEnabled,
             &m_setuptab, &SetupTab::onControlTabEnabled);
}

void SetupViewMgr::WireMessages(){

    connect(&m_instrument, &Instrument::NotifyErrorDetected,
            &m_setuptab, &SetupTab::onStatusUpdated);
    connect(&m_instrument, &Instrument::NotifyStatusUpdated,
            &m_setuptab, &SetupTab::onStatusUpdated);
    connect(this, &SetupViewMgr::NotifyStatusUpdated,
            &m_setuptab, &SetupTab::onStatusUpdated);

}
