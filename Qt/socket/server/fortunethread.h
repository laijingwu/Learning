#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QDataStream>
#include <QTextStream>
#include <QDebug>

class FortuneThread : public QThread
{
    Q_OBJECT

public:
    FortuneThread(int socketDescriptor, const QString &fortune, QObject *parent);
    QTcpSocket *s;

protected:
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);

private slots:
    void revData();
    void disConnected();

private:
    int socketDescriptor;
    QString text;
    bool isConnected;
};
