#ifndef SETUPTAB_H
#define SETUPTAB_H

#include <QWidget>

namespace Ui {
class setuptab;
}

class setuptab : public QWidget
{
    Q_OBJECT

public:
    explicit setuptab(QWidget *parent = nullptr);
    ~setuptab();

private:
    Ui::setuptab *ui;
};

#endif // SETUPTAB_H
