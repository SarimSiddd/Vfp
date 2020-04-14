#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup(QObject *parent = nullptr);

signals:

};

#endif // STARTUP_H
