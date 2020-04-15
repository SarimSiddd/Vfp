#pragma once
#include "Model/instsocket.h"
#include "utils.h"
#include <QDebug>


class Instrument : public QObject
{
    Q_OBJECT
public:
    explicit Instrument(QObject *parent, InstSocket& sock);
    virtual ~Instrument();
    void Connect();
    void Disconnect() const;
    bool IsConnected() const;
    QString GetHostName() const;
    quint16 GetPort() const;
    void SetLongWaitMs(int value);
    void SetShortWaitMs(int value);
    double getPulseWidth() const {return m_pulseWidth;}
    double getPulseDelay() const {return m_pulseDelay;}
    bool getSynth1() const {return m_synth1;}
    bool getSynth2() const {return m_synth2;}
    void setPulseWidth(double width);
    void setPulseDelay(double delay);
    void setSynth1(bool isEnabled);
    void setSynth2(bool isEnabled);


signals:
    void NotifyConnected();
    void NotifyDisconnected();
    void NotifyDataSent(const QString& dataSent);
    void NotifyDataReceived(const QString& readData);
    void NotifyErrorDetected(const QString& errorMsg);
    void NotifyStatusUpdated(const QString& statusMsg);
    void NotifyDelayUpdated(const double& value);
    void NotifyValueUpdated(const double& value);

public slots:
    void onHostNameChanged(const QString& hostName);
    void onPortChanged(quint16 port);
    void onConnected();
    void onDisconnected();
    void onSendRequest(const QString& dataToSend);
    void onReceiveRequest();


private:
    InstSocket& m_instSocket;
    QString m_lastCommandSent;
    double m_pulseDelay;
    double m_pulseWidth;
    bool m_synth1;
    bool m_synth2;

    void WireConnections();

    //explicit Instrument(const Instrument& rhs) = delete;
    //Instrument& operator= (const Instrument& rhs) = delete;
};
