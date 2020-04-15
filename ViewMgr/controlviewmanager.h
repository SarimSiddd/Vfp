#ifndef CONTROLVIEWMANAGER_H
#define CONTROLVIEWMANAGER_H
#include <View/controltab.h>
#include <Model/instrument.h>
#include "utils.h"
#include <QObject>

class ControlViewManager : public QObject
{
    Q_OBJECT
public:
    explicit ControlViewManager(QObject* parent, Instrument &instrument, ControlTab &controltab);

~ControlViewManager();

signals:
    void NotifyDisconnected();
    void NotifyConnected();

private:
    void WireButtons();
    void WireDisplay();
    void WireView();
    Instrument &m_instrument;
    ControlTab &m_controltab;
    void Disconnected();
    void Connected();

private slots:
    void onConnected();
    void onDisconnected();
};

#endif // CONTROLVIEWMANAGER_H
