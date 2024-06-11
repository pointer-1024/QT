#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int num = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("模拟大棚");
    currentTime = 0;
    // 创建并设置父对象
    timer = new QTimer(this);
    server = new QTcpServer(this);
    socket = new QTcpSocket(this);

    // 启动服务器监听
    if (!server->listen(QHostAddress::AnyIPv4, 8000)) {
        QMessageBox::critical(this, "错误", "无法启动服务器");
        return;
    }

    // 连接服务器的newConnection信号到槽函数
    connect(server, &QTcpServer::newConnection, this, &Widget::newClientHandler);
    // 连接定时器的timeout信号到槽函数
    connect(timer, &QTimer::timeout, this, &Widget::checkServerStatus);
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

//连接测试
void Widget::newClientHandler()
{
    //QTcpSocket *socket = server->nextPendingConnection();
    socket = server->nextPendingConnection();
    if (socket) {
        QMessageBox::information(this, "提示", "控制台已连接");

        // 立即向客户端发送数据

    }
}

//数据发送
void Widget::checkServerStatus()
{
    // 检查服务器状态，这里可以执行一些定时任务
    if (server->isListening()) {
        QString buf = socket->readAll();
        qDebug() << buf;
        if(buf != "") readClientData(buf);
    } else {
        qDebug() << "服务器未在监听";
    }

    QByteArray str;
    update();
    str += "\n大棚1\n";
    str += "温度:" + QByteArray::number(shed[0].temp) + "℃\n";
    str += "湿度:" + QByteArray::number(shed[0].humi) + "%\n";
    QByteArray text = (shed[0].fun ? "on" : "off");
    str += "风扇:" + text + "\n";
    text = (shed[0].heater ? "on" : "off");
    str += "加热器:" + text + "\n";

    str += "\n大棚2\n";
    str += "温度:" + QByteArray::number(shed[1].temp) + "℃\n";
    str += "湿度:" + QByteArray::number(shed[1].humi) + "%\n";
    text = (shed[1].fun ? "on" : "off");
    str += "风扇:" + text + "\n";
    text = (shed[1].heater ? "on" : "off");
    str += "加热器:" + text + "\n";

    str += "\n大棚3\n";
    str += "温度:" + QByteArray::number(shed[2].temp) + "℃\n";
    str += "湿度:" + QByteArray::number(shed[2].humi) + "%\n";
    text = (shed[2].fun ? "on" : "off");
    str += "风扇:" + text + "\n";
    text = (shed[2].heater ? "on" : "off");
    str += "加热器:" + text + "\n";
    socket->write(str);
}

//温湿度模拟
std::pair<int,int> Widget::simulateEnvironment1(int time)
{
    int temperature = 20.0 + 10.0 * std::sin(time / 10.0);
    int humidity = 50.0 + 10.0 * std::sin(time / 15.0) + 5.0 * std::cos(time / 8.0);
    int num1 = shed[0].fun ? -2 : 0;
    int num2 = shed[0].heater ? 1 : 0;
    return std::make_pair(temperature + num1 + num2, humidity - num2);
}

std::pair<int, int> Widget::simulateEnvironment2(int time)
{
    int temperature = 25.0 + 5.0 * std::cos(time / 5.0);
    int humidity = 55.0 + 15.0 * std::cos(time / 12.0) + 3.0 * std::sin(time / 9.0);
    int num1 = shed[1].fun ? -2 : 0;
    int num2 = shed[1].heater ? 1 : 0;
    return std::make_pair(temperature + num1 + num2, humidity - num2);
}

std::pair<int, int> Widget::simulateEnvironment3(int time)
{
    int temperature = 22.0 + 8.0 * std::sin(time / 7.0) + 2.0 * std::cos(time / 3.0);
    int humidity = 60.0 + 12.0 * std::sin(time / 20.0) + 6.0 * std::cos(time / 6.0);
    int num1 = shed[2].fun ? -2 : 0;
    int num2 = shed[2].heater ? 1 : 0;
    return std::make_pair(temperature + num1 + num2, humidity - num2);
}

//更新数据
void Widget::update()
{

    currentTime += 1;
    //大棚1
    auto val = simulateEnvironment1(currentTime);
    shed[0].temp = val.first;
    shed[0].humi = val.second;
    shed[0].fun = strSpilt(ui->label_10->text()) == "off" ? false : true;
    shed[0].heater = strSpilt(ui->label_11->text()) == "off" ? false : true;
    QByteArray text = "当前温度:" + QByteArray::number(shed[0].temp) + "℃";
    ui->label->setText(text);
    text = "当前湿度:" + QByteArray::number(shed[0].humi) + "%";
    ui->label_2->setText(text);

    //大棚2
    val = simulateEnvironment2(currentTime);
    shed[1].temp = val.first;
    shed[1].humi = val.second;
    shed[1].fun = strSpilt(ui->label_13->text()) == "off" ? false : true;
    shed[1].heater = strSpilt(ui->label_12->text()) == "off" ? false : true;
    text = "当前温度:" + QByteArray::number(shed[1].temp) + "℃";
    ui->label_3->setText(text);
    text = "当前湿度:" + QByteArray::number(shed[1].humi) + "%";
    ui->label_4->setText(text);

    //大棚3
    val = simulateEnvironment3(currentTime);
    shed[2].temp = val.first;
    shed[2].humi = val.second;
    shed[2].fun = strSpilt(ui->label_15->text()) == "off" ? false : true;
    shed[2].heater = strSpilt(ui->label_14->text()) == "off" ? false : true;
    text = "当前温度:" + QByteArray::number(shed[2].temp) + "℃";
    ui->label_5->setText(text);
    text = "当前湿度:" + QByteArray::number(shed[2].humi) + "%";
    ui->label_6->setText(text);
}

//获取lable上的数据
QString Widget::strSpilt(const QString &str)
{
    QStringList parts = str.split(':');
       if (parts.size() == 2) {
           num = parts.at(0).toInt();
           return parts.at(1);
       }
    return "null";
}

//修改状态
void Widget::readClientData(const QString &str)
{
    QString status = strSpilt(str);
    switch (num) {
    case 1: ui->label_10->setText("风扇:" + status); break;
    case 2: ui->label_11->setText("加热器:" + status); break;
    case 3: ui->label_12->setText("加热器:" + status); break;
    case 4: ui->label_13->setText("风扇:" + status); break;
    case 5: ui->label_14->setText("风扇:" + status); break;
    case 6: ui->label_15->setText("加热器:" + status); break;
    }
    qDebug() << "str = " << str;
    qDebug() << "label" << status;
}
