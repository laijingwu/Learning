#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setText(QString("127.0.0.1"));
    ui->lineEdit_2->setText(QString("6666"));
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);

    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readFortune()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(requestNewFortune()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(sendFortune()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(closeFortune()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::requestNewFortune()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    tcpSocket->abort();
    tcpSocket->connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
}

void Widget::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, tr("Fortune Client"),
                    tr("The host was not found. Please check the "
                    "host name and port settings."));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, tr("Fortune Client"),
                    tr("The connection was refused by the peer. "
                    "Make sure the fortune server is running, "
                    "and check that the host name and port "
                    "settings are correct."));
            break;
        default:
            QMessageBox::information(this, tr("Fortune Client"),
                    tr("The following error occurred: %1.")
                    .arg(tcpSocket->errorString()));
        }
     ui->pushButton->setEnabled(true);
}

void Widget::readFortune()
{
    QString nextFortune = tcpSocket->readAll();
    ui->label->setText(nextFortune);
}

void Widget::sendFortune()
{
    QString str = ui->lineEdit_3->text();
    if (!str.isEmpty())
        tcpSocket->write(str.toLocal8Bit());
    ui->lineEdit_3->clear();
}

void Widget::closeFortune()
{
    tcpSocket->close();
    tcpSocket->abort();
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(true);
    ui->lineEdit_3->setEnabled(false);
    ui->label->clear();
}
