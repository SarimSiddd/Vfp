#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "View/setuptab.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent, SetupTab &setup);
    ~MainView();

private:
      Ui::MainView *ui;
      SetupTab &m_setuptab;

};
#endif // MAINVIEW_H
