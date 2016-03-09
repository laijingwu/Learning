#include "myserver.h"
#include "fortunethread.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{
    fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
             << tr("You've got to think about tomorrow.")
             << tr("You will be surprised by a loud noise.")
             << tr("You will feel hungry again in another hour.")
             << tr("You might have mail.")
             << tr("You cannot kill time without injuring eternity.")
             << tr("Computers are not intelligent. They only think they are.");
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "接收到连接";
    QString fortune = fortunes.at(qrand() % fortunes.size());
    FortuneThread *thread = new FortuneThread(socketDescriptor, fortune, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
