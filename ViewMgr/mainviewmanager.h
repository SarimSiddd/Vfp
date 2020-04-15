#ifndef MAINVIEWMANAGER_H
#define MAINVIEWMANAGER_H

#include <QObject>
#include "ViewMgr/setupviewmgr.h"
#include "ViewMgr/controlviewmanager.h"

class MainViewManager : public QObject
{
    Q_OBJECT
public:
    explicit MainViewManager(QObject *parent, ControlViewManager& conMgr, SetupViewMgr& setupMgr);

signals:
    void NotifyConnected();
    void NotifyDisconnected();

private slots:
    void onConnected();
    void onDisconnected();

private:
    SetupViewMgr &m_setupViewMgr;
    ControlViewManager &m_controlViewMgr;
    void WireViews();
};

#endif // MAINVIEWMANAGER_H
