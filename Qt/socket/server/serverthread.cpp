#include "serverthread.h"
#include "myserver.h"

ServerThread::ServerThread(QObject *parent) : QThread(parent)
{
}

void ServerThread::run()
{
    MyServer *server = new MyServer();
    server->listen(QHostAddress::Any, 6666);
    qDebug() << "正在监听6666端口";
}
