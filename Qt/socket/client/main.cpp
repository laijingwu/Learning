#include <QCoreApplication>
#include <client.h>
#include <QTextStream>
#include <QTime>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client cl;
    cl.init();

    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    cl.send(QString("hello world!"));

    dieTime = QTime::currentTime().addMSecs(1000);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    while(1)
    {
        char str[100];
        cin >> str;
        cl.send(QString(str));
        a.processEvents();
    }
    /*QTextStream in(stdin);
    while(1)
    {
        QString str;
        in >> str;
        cl.send(str);
    }*/
    return a.exec();
}

