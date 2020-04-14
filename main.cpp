#include "startup.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Startup startup;
    //MainView w(new QWidget, &new SetupTab);
    startup.show();
    return a.exec();
}
