#include "utils.h"

static QString DESTRUCTOR_MSG = "Calling destructor of objectname [%1]";

Utils::Utils()
{    

}

void Utils::DestructorMsg (const QString &msg){

    qDebug() << DESTRUCTOR_MSG.arg(msg);

}

void Utils::DestructorMsg(const QObject * const obj){

    DestructorMsg(obj->metaObject()->className());
}
