#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "View/setuptab.h"
#include "View/controltab.h"
#include "View/aboutbox.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent, SetupTab &setup, ControlTab &control);
    ~MainView();

private:
      Ui::MainView *ui;
      SetupTab &m_setuptab;
      ControlTab &m_controltab;

      void WireViews();

signals:
    void NotifyDisconnected();
    void NotifyConnected();

private slots:
    void onDisconnected();
    void onConnected();
    void on_action_Exit_triggered();
    void on_action_About_triggered();
};
#endif // MAINVIEW_H
