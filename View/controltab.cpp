#include "controltab.h"
#include "ui_controltab.h"

ControlTab::ControlTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlTab)
{
    ui->setupUi(this);
}

void ControlTab::onDisconnected(){

    this->setEnabled(false);
}

void ControlTab::onConnected(){

    this->setEnabled(true);
}


ControlTab::~ControlTab()
{
    Utils::DestructorMsg(this);
    delete ui;
}



void ControlTab::on_sbWidth_valueChanged(double value)
{
    emit NotifyWidthChanged(value);
}

void ControlTab::on_sbDelay_valueChanged(double value)
{
    emit NotifyDelayChanged(value);
}
