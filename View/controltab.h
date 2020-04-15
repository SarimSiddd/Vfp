#ifndef CONTROLTAB_H
#define CONTROLTAB_H

#include <QWidget>
#include "utils.h"

namespace Ui {
class ControlTab;
}

class ControlTab : public QWidget
{
    Q_OBJECT

public:
    explicit ControlTab(QWidget *parent = nullptr);
    ~ControlTab();

signals:
    void NotifyWidthChanged(double width);
    void NotifyDelayChanged(double delay);

public slots:
    void onDisconnected();
    void onConnected();

private slots:
    void on_sbWidth_valueChanged(double arg1);
    void on_sbDelay_valueChanged(double arg1);

private:
    Ui::ControlTab *ui;
};

#endif // CONTROLTAB_H
