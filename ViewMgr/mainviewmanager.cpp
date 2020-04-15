#include "mainviewmanager.h"

MainViewManager::MainViewManager(QObject *parent, ControlViewManager& conMgr, SetupViewMgr& setupMgr) :
    QObject(parent), m_setupViewMgr(setupMgr), m_controlViewMgr(conMgr)
{

    WireViews();
}

void MainViewManager::onConnected(){

}

void MainViewManager::onDisconnected(){

}

void MainViewManager::WireViews(){

   // connect(&m_setupViewMgr, &SetupViewMgr::NotifyConnectEnabled,
     //        &m_controlViewMgr, &ControlViewManager::onConnecte
}
