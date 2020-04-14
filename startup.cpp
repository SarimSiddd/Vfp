#include "startup.h"

Startup::Startup() : QObject(nullptr),
    m_setuptab(*new SetupTab(nullptr)),
    m_mainview(*new MainView(nullptr, m_setuptab)),
    m_instrument(new Instrument(this, *new InstSocket(this))),
    m_setupviewmgr(new SetupViewMgr (this, *m_instrument,
                                     Provider::GetSettingsAsSingleton(),
                                     m_setuptab))
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
