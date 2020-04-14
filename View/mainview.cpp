#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent, SetupTab &setuptab)
    : QMainWindow(parent)
    , ui(new Ui::MainView), m_setuptab(setuptab)
{

    ui->setupUi(this);
    m_setuptab.setParent(this);
    //auto setup_tab= new setuptab(this);
    ui->loSetupTab->addWidget(&m_setuptab);
}

MainView::~MainView()
{
    delete ui;
}

