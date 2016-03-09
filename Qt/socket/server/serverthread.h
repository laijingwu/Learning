#include <QThread>
#include <QObject>
#include <QTextStream>
#include <QHostAddress>
#include <QTcpServer>
#include <QtNetwork>
#include <QDebug>

class ServerThread : public QThread
{
    Q_OBJECT

public:
    ServerThread(QObject *parent = 0);

protected:
    void run();
};

