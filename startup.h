#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include "View/mainview.h"
#include "View/setuptab.h"
#include "View/controltab.h"
#include "ViewMgr/setupviewmgr.h"
#include "ViewMgr/controlviewmanager.h"
#include "utils.h"
#include "Model/settings.h"
#include "Model/provider.h"
#include "Model/instrument.h"



class Startup final: public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void show() const;
    ~Startup();

private:
    SetupTab &m_setuptab;
    ControlTab &m_controltab;
    MainView &m_mainview;
    Instrument *m_instrument;
    SetupViewMgr *m_setupviewmgr;
    ControlViewManager *m_controlviewmgr;

signals:

};

#endif // STARTUP_H
