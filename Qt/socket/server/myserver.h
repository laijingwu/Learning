#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QtNetwork>
#include <QStringList>
#include <QHostAddress>
#include <QDebug>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QObject *parent = 0);

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;

private:
    QStringList fortunes;
};

