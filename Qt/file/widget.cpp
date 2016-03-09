#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Btn_onclicked()));

    // 设置默认编码
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

void Widget::Btn_onclicked()
{
    // 创建文件操作对象
    QFile *fp = new QFile("test.txt");

    // 检查文件是否存在
    if (!fp->exists()) {
        QMessageBox::critical(this, "Error", fp->errorString());
        return;
    }

    // 打开文件
    if (!fp->open(QIODevice::ReadWrite|QIODevice::Text)) {
        QMessageBox::critical(this, "Error", fp->errorString());
        return;
    }

    // 使用文本流对文件进行操作
    QTextStream out(fp);
    //out.setCodec("UTF-8");    // 设置编码
    QString text = out.readAll();
    ui->textEdit->setText(text);

    // 移动指针到末端并写入
    //fp->seek(fp->size());
    //out << "\r\n" << QString("321TEST");

    // 关闭文件
    fp->close();
    delete fp;

    // 设置textedit滚动到末端
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}
