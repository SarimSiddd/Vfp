#include "setuptab.h"
#include "ui_setuptab.h"
#include "utils.h"

SetupTab::SetupTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetupTab)
{
    ui->setupUi(this);
}

SetupTab::~SetupTab()
{
    Utils::DestructorMsg(this);
    delete ui;
}

void SetupTab::SetupTab::onStatusUpdated(const QString &statusMsg)
{
    ui->teInstrumentMesage->append(statusMsg);
}

void SetupTab::onConnected()
{
    auto connect_msg = QString("Connected");
    ui->teInstrumentMesage->append(connect_msg);
}

void SetupTab::onDisconnected()
{
    auto disconnect_msg = QString("Disconnected");
    ui->teInstrumentMesage->append(disconnect_msg);
}

void SetupTab::onDataSent(const QString &dataSent)
{
    ui->teInstrumentMesage->append("Data sent: " + dataSent);
}

void SetupTab::onDataReceived(const QString &dataRead)
{
    ui->teInstrumentMesage->append("Data received: " + dataRead);
}

void SetupTab::onConnectEnabled(bool isEnabled)
{
    ui->btnConnect->setEnabled(isEnabled);
}

void SetupTab::onDisconnectEnabled(bool isEnabled)
{
    ui->btnDisconnect->setEnabled(isEnabled);
}

void SetupTab::onDirectCommandsEnabled(bool isEnabled)
{
    ui->gbDirectCommands->setEnabled(isEnabled);
}

void SetupTab::onControlTabEnabled(bool isEnabled)
{
   //TODO
}

void SetupTab::SetHostName(const QString& value){

    ui->leIPAddress->setText(value);
    emit NotifyHostNameChanged(value);
}


void SetupTab::SetPort(const quint16 value){

    ui->lePort->setText(QString::number(value));
    emit NotifyPortChanged(value);
}

void SetupTab::SetCommands(QStringListModel &commands){

    ui->cmbCommands->setModel(&commands);
}

void SetupTab::on_leIPAddress_editingFinished()
{
    emit NotifyHostNameChanged(ui->leIPAddress->text());

}

void SetupTab::on_lePort_editingFinished()
{
    bool ok;
    int result = ui->lePort->text().toInt(&ok);
    if (!ok || (result > USHRT_MAX)){

        ui->teInstrumentMesage->append("Invalid Port Number");
    }
    else {
        emit NotifyPortChanged(result);
    }

}


void SetupTab::on_btnConnect_clicked()
{
    emit NotifyConnectClicked();
}

void SetupTab::on_btnDisconnect_clicked()
{
    emit NotifyDisconnectClicked();
}

void SetupTab::on_btnSend_clicked()
{
    emit NotifySendClicked(ui->cmbCommands->currentText());
}

void SetupTab::on_btnReceive_clicked()
{
    emit NotifyReceiveClicked();
}

void SetupTab::on_btnClear_clicked()
{
    ui->teInstrumentMesage->clear();
}
