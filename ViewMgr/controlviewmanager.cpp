#include "controlviewmanager.h"

ControlViewManager::ControlViewManager(QObject* parent,
                                       Instrument &instrument,
                                       ControlTab &controltab):
                                       QObject(parent),
                                       m_instrument(instrument),
                                       m_controltab(controltab)
{
    WireView();
    WireDisplay();
    Disconnected();
}

void ControlViewManager::WireButtons()
{

}

void ControlViewManager::Disconnected(){

    emit NotifyDisconnected();
}

void ControlViewManager::Connected(){

    emit NotifyConnected();
}

void ControlViewManager::onConnected()
{
    Connected();
}

void ControlViewManager::onDisconnected()
{
    Disconnected();
}

void ControlViewManager::WireDisplay()
{
    connect(&m_instrument, &Instrument::NotifyDisconnected,
             this, &ControlViewManager::onDisconnected);
    connect(&m_instrument, &Instrument::NotifyConnected,
             this, &ControlViewManager::onConnected);
}

void ControlViewManager::WireView(){

    connect(this, &ControlViewManager::NotifyDisconnected,
            &m_controltab, &ControlTab::onDisconnected);
    connect(this, &ControlViewManager::NotifyConnected,
            &m_controltab, &ControlTab::onConnected);
}

ControlViewManager::~ControlViewManager(){

    Utils::DestructorMsg(this);
}
