#include "fortunethread.h"

FortuneThread::FortuneThread(int socketDescriptor, const QString &fortune, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor), text(fortune) , isConnected(0)
{

}

void FortuneThread::run()
{
    QTcpSocket tcpSocket;

    if (!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        emit error(tcpSocket.error());
        return;
    }
    isConnected = 1;
    s = &tcpSocket;
    connect(&tcpSocket,SIGNAL(readyRead()),this,SLOT(revData()), Qt::DirectConnection);
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(disConnected()), Qt::DirectConnection);
    QByteArray block;
    block = text.toLatin1();
    qDebug() << "已发送信息：" << block;
    tcpSocket.write(block);
    //tcpSocket.disconnectFromHost();
    //tcpSocket.waitForDisconnected();
    while(isConnected)
    {
        tcpSocket.waitForReadyRead();
    }
}

void FortuneThread::disConnected()
{
    isConnected = 0;
    qDebug() << "断开连接 结束循环";
}

void FortuneThread::revData()
{
    QByteArray res = s->readAll();
    qDebug() << "收到信息：" << QString::fromLocal8Bit(res);

    qDebug() << "已发送信息：respond";
    s->write("respond");
}
