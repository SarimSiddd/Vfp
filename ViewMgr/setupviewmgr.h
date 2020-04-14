#ifndef SETUPVIEWMGR_H
#define SETUPVIEWMGR_H

#include <QObject>
#include "Model/instrument.h"
#include "Model/settings.h"
#include "View/setuptab.h"
#include "utils.h"

class SetupViewMgr : public QObject
{
    Q_OBJECT
public:
    explicit SetupViewMgr(QObject *parent,
                          Instrument &instrument,
                          Settings &settings,
                          SetupTab &setuptab);

public slots:
    void onConnected();
    void onDisconnected();


private:

    Instrument &m_instrument;
    //Settings &m_settings;
    SetupTab &m_setuptab;

    ~SetupViewMgr();

    void WireSettings(Settings &config);
    void WireHostAndPort();
    void WireMessages();
    void WireButtons();
    void WireDisplayUpdate();
signals:

    void NotifyStatusUpdated(const QString& value);
    void NotifyConnectEnabled(bool value);
    void NotifyDisConnectEnabled(bool value);
    void NotifyDirectCommandsEnabled(bool value);
    void NotifyControlTabEnabled(bool value);

};

#endif // SETUPVIEWMGR_H
