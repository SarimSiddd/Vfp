#ifndef SETUPTAB_H
#define SETUPTAB_H

#include <QWidget>
#include <QStringListModel>

namespace Ui {
class SetupTab;
}

class SetupTab : public QWidget
{
    Q_OBJECT

public:
    explicit SetupTab(QWidget *parent = nullptr);
    ~SetupTab();

    void SetHostName(const QString &value);
    void SetPort(const quint16 value);
    void SetCommands(QStringListModel &commands);

signals:
    void NotifyHostNameChanged(const QString& value);
    void NotifyPortChanged(quint16 value);
    void NotifyConnectClicked();
    void NotifyDisconnectClicked();
    void NotifySendClicked(const QString& dataToSend);
    void NotifyReceiveClicked();

public slots:
    void onStatusUpdated(const QString &statusMsg);
    void onConnected();
    void onDisconnected();
    void onDataSent(const QString& dataSent);
    void onDataReceived(const QString& dataRead);
    void onConnectEnabled (bool isEnabled);
    void onDisconnectEnabled (bool isEnabled);
    void onDirectCommandsEnabled (bool isEnabled);
    void onControlTabEnabled (bool isEnabled);

private slots:
    void on_leIPAddress_editingFinished();
    void on_lePort_editingFinished();
    void on_btnConnect_clicked();
    void on_btnDisconnect_clicked();
    void on_btnSend_clicked();
    void on_btnReceive_clicked();
    void on_btnClear_clicked();

private:
    Ui::SetupTab *ui;

};

#endif // SETUPTAB_H
