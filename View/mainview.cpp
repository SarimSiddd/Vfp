#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent, SetupTab &setuptab, ControlTab &control)
    : QMainWindow(parent)
    , ui(new Ui::MainView), m_setuptab(setuptab), m_controltab(control)
{

    ui->setupUi(this);
    m_setuptab.setParent(this);
    m_controltab.setParent(this);

    ui->loSetupTab->addWidget(&m_setuptab);
    ui->loControlTab->addWidget(&m_controltab);
    onDisconnected();
}

MainView::~MainView()
{
    delete ui;
}

void MainView::onDisconnected()
{
    emit NotifyDisconnected();
}

void MainView::onConnected()
{
    emit NotifyConnected();
}

void MainView::WireViews(){

}


void MainView::on_action_Exit_triggered()
{
    QApplication::quit();
}

void MainView::on_action_About_triggered()
{
    AboutBox about_box;
    about_box.show();
    about_box.exec();
}
