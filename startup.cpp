#include "startup.h"
#include "utils.h"
#include "Model/settings.h"
#include "Model/provider.h"

Startup::Startup() : QObject(nullptr),
    m_setuptab(*new SetupTab(nullptr)), m_mainview(*new MainView(nullptr, m_setuptab))
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
