#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include <View/mainview.h>
#include <View/setuptab.h>

class Startup final: public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void show() const;
    ~Startup();

private:
    SetupTab &m_setuptab;
    MainView &m_mainview;

signals:

};

#endif // STARTUP_H
