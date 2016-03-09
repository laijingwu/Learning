#include "client.h"

Client::Client()
{
}

Client::~Client()
{
}

void Client::init()
{
    this->tcpSocket = new QTcpSocket(this);
    newConnection();
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(revData()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
}

void Client::revData()
{
    QString datas = tcpSocket->readAll();
    qDebug() << "收到信息：" << datas;
}

void Client::newConnection()
{
    tcpSocket->abort();
    tcpSocket->connectToHost("127.0.0.1",6666);
    qDebug() << "已连接";
}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
    tcpSocket->close();
}

void Client::send(QString text)
{
    QByteArray block;
    block = text.toLatin1();
    tcpSocket->write(block);
    qDebug() << block << "已发送";
}
