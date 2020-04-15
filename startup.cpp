#include "startup.h"

Startup::Startup() : QObject(nullptr),
    m_setuptab(*new SetupTab(nullptr)),
    m_controltab(*new ControlTab(nullptr)),
    m_mainview(*new MainView(nullptr, m_setuptab, m_controltab)),
    m_instrument(new Instrument(this, *new InstSocket(this))),
    m_setupviewmgr(new SetupViewMgr (this, *m_instrument,
                                     Provider::GetSettingsAsSingleton(),
                                     m_setuptab)),
    m_controlviewmgr(new ControlViewManager(this, *m_instrument, m_controltab))
{
    Settings& my_settings = Provider::GetSettingsAsSingleton();
    my_settings.ParseJsonData();
}

void Startup::show() const{

    m_mainview.show();
}


Startup::~Startup(){

    Utils::DestructorMsg(this);
    delete &m_mainview;

}
