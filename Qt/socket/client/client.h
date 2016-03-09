#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QObject>
#include <QAbstractSocket>
#include <QTextStream>
#include <QTime>
#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>

class Client : public QObject
{
    Q_OBJECT

public:
    Client();
    ~Client	();
    void init();
    void newConnection();
    void send(QString text);

private slots:
    void revData();
    void displayError(QAbstractSocket::SocketError);

private:
    QTcpSocket *tcpSocket;
};
