#include "setuptab.h"
#include "ui_setuptab.h"

setuptab::setuptab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setuptab)
{
    ui->setupUi(this);
}

setuptab::~setuptab()
{
    delete ui;
}
