#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("控制台");
    socket = new QTcpSocket(this); // 设置父对象以确保自动删除
    dt = QDateTime::currentDateTime();
    timer = new QTimer(this);

    //设置文本为只读模式
    ui->textEdit->setReadOnly(true);

    // 连接到服务器
    socket->connectToHost("127.0.0.1", 8000);

    // 处理readyRead信号
    connect(socket, &QTcpSocket::readyRead, this, [=]() {
        QByteArray data = socket->readAll();
        ui->textEdit->setText(data);

    });

    // 检查是否连接成功
    connect(socket, &QTcpSocket::connected, this, [&](){
        if(socket->isOpen() == true){
             qDebug() << "Connected to server!";
             timer->stop();
        }else{
            connect(timer,&QTimer::timeout,this,&Widget::clientConnect);
            timer->start(100);
        }

    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::clientConnect()
{
    socket->connectToHost("127.0.0.1", 8000);
}

void Widget::on_pushButton_clicked()
{
    if(!buttonCheck1){
        socket->write("1:on");
        ui->pushButton->setText("关");
        buttonCheck1 = true;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚1风扇打开\n");

    } else {
        socket->write("1:off");
        ui->pushButton->setText("开");
        buttonCheck1 = false;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
         ui->textEdit_2->insertPlainText(" 大棚1风扇关闭\n");
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(!buttonCheck2){
        socket->write("2:on");
        ui->pushButton_2->setText("关");
        buttonCheck2 = true;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚1加热器打开\n");
    } else {
        socket->write("2:off");
        ui->pushButton_2->setText("开");
        buttonCheck2 = false;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚1加热器关闭\n");
    }

}

void Widget::on_pushButton_3_clicked()
{
    if(!buttonCheck3){
        socket->write("3:on");
        ui->pushButton_3->setText("关");
        buttonCheck3 = true;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚2加热器打开\n");

    } else {
        socket->write("3:off");
        ui->pushButton_3->setText("开");
        buttonCheck3 = false;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚2加热器关闭\n");

    }
}

void Widget::on_pushButton_4_clicked()
{
    if(!buttonCheck4){
        socket->write("4:on");
        ui->pushButton_4->setText("关");
        buttonCheck4 = true;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚2风扇打开\n");

    } else {
        socket->write("4:off");
        ui->pushButton_4->setText("开");
        buttonCheck4 = false;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚2风扇关闭\n");
    }
}

void Widget::on_pushButton_5_clicked()
{
    if(!buttonCheck5){
        socket->write("5:on");
        ui->pushButton_5->setText("关");
        buttonCheck5 = true;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚3加热器打开\n");
    } else {
        socket->write("5:off");
        ui->pushButton_5->setText("开");
        buttonCheck5 = false;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚3加热器关闭\n");
    }
}

void Widget::on_pushButton_6_clicked()
{
    if(!buttonCheck6){
        socket->write("6:on");
        ui->pushButton_6->setText("关");
        buttonCheck6 = true;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚3风扇打开\n");
    } else {
        socket->write("6:off");
        ui->pushButton_6->setText("开");
        buttonCheck6 = false;
        ui->textEdit_2->insertPlainText(dt.currentDateTime().toString());
        ui->textEdit_2->insertPlainText(" 大棚3风扇关闭\n");
    }
}

