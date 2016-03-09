#include <QCoreApplication>
#include <QObject>
#include <QThread>
#include <QDebug>
//#include "serverthread.h"
#include "myserver.h"
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*ServerThread *serthread = new ServerThread();
    QObject::connect(serthread, SIGNAL(finished()), serthread, SLOT(deleteLater()));
    serthread->start();*/
    MyServer *server = new MyServer();
    server->listen(QHostAddress::Any, 6666);
    qDebug() << "正在监听6666端口";

    return a.exec();
}
