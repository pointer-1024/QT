#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //成员变量初始化
    //定时器尝试
    timer = new QTimer(this);

    //串口初始化
    serial = new QSerialPort;

    //数据初始化
    packet.fun = false;
    packet.led = false;
    packet.angle = 0;
    packet.temperature = 0;
    packet.humidity = 0;

    //界面初始化
    ui->setupUi(this);
    this->setWindowTitle("显示界面");
    this->setFixedSize(800,600);
    //this->setStyleSheet("QMainWindow { background-image: url(:/1.png); }");
    connect(serial,&QSerialPort::readyRead,this,&MainWindow::receive);
    connect(timer,&QTimer::timeout,this,&MainWindow::onTimeOut);
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap(":/1.png");
    painter.setOpacity(0.3);
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);
    QMainWindow::paintEvent(event);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_5_clicked()
{
    //清空串口
    ui->comboBox->clear();

    //遍历串口
    foreach(const auto &info,QSerialPortInfo::availablePorts()){
        ui->comboBox->addItem(info.portName());
    }
}

void MainWindow::on_pushButton_clicked()
{
    //串口号
    serial->setPortName(ui->comboBox->currentText());
    //波特率
    serial->setBaudRate(ui->comboBox_2->currentText().toUInt());
    //停止位
    switch(ui->comboBox_3->currentIndex()){
        case 0: serial->setStopBits(QSerialPort::OneStop); break;
        case 1: serial->setStopBits(QSerialPort::OneAndHalfStop); break;
    case 2: serial->setStopBits(QSerialPort::TwoStop); break;
    }
    //数据位
    switch(ui->comboBox_4->currentText().toUInt()){
        case 8: serial->setDataBits(QSerialPort::Data8); break;
        case 7: serial->setDataBits(QSerialPort::Data7); break;
        case 6: serial->setDataBits(QSerialPort::Data6); break;
        case 5: serial->setDataBits(QSerialPort::Data5); break;
    }
    //校验位
    switch(ui->comboBox_5->currentIndex()){
        case 0: serial->setParity(QSerialPort::NoParity); break;
        case 1: serial->setParity(QSerialPort::EvenParity);break;
        case 2: serial->setParity(QSerialPort::OddParity); break;
    }

    serial->open(QSerialPort::ReadWrite);

    if(serial->isOpen()){
        ui->label_6->setText("串口打开");
    }else{
        ui->label_6->setText("打开失败");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    serial->close();
    ui->comboBox->clear();
    ui->label_6->setText("串口关闭");
}

void MainWindow::receive()
{
    QByteArray data = serial->readAll();
    ui->textEdit->insertPlainText(QString(data).toUtf8());

    unpacking(packet,data);
    QString str;

    str = packet.led ? "on" : "off";
    ui->label_11->setText(str);

    str = QString::number(packet.temperature) + "℃";
    ui->label_12->setText(str);

    str = QString::number(packet.humidity) + "%";
    ui->label_13->setText(str);

    str = packet.fun ? "on" : "off";
    ui->label_14->setText(str);

    str = QString::number(packet.angle) + "°";
    ui->label_16->setText(str);
}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray data;
    QString str = ui->textEdit->toPlainText().toUtf8();

    for(int i = 0; i < str.size(); i++){
        if(str.at(i) != ' '){
            data.append(str.at(i));
        }
    }

    QStringList field = QString(data).split('=');
    if(field.size() == 2){
        if(field[0] == "led"){
            packet.led = field[1] == "on" ? 1 : 0;
        }

        if(field[0] == "angle"){
            packet.angle = field[1].toUInt();
        }

        if(field[0] == "fun"){
            packet.fun = field[1] == "on" ? 1 : 0;
        }
    }

    packing(date,packet,data);
    ui->textEdit->clear();
    serial->write(data);
}

//解包
void MainWindow::unpacking(dataPacket &data, const QByteArray &array)
{
    QDomDocument docs;

//    if(!docs.setContent(array)){
//        QMessageBox::warning(this,"提示","格式错误");
//       return;
//    }
    docs.setContent(array);
    qDebug() << array;
    QDomElement doc = docs.firstChildElement();

    QDomElement elem = doc.firstChildElement("fun");
    data.fun = elem.text().toUInt() ? true : false;


    elem = doc.firstChildElement("led");
    data.led = elem.text().toUInt() ? true : false;

    elem = doc.firstChildElement("angle");
    data.angle = elem.text().toUInt();

    elem = doc.firstChildElement("temperature");
    data.temperature = elem.text().toUInt();

    elem = doc.firstChildElement("humidity");
    data.humidity = elem.text().toUInt();
}

//打包
void MainWindow::packing(const datePacket &date,const dataPacket &data,QByteArray& array)
{
//    <root>
//    <fun>0</fun>
//    <led>0</led>
//    <angle>0</angle>
//    <temperature>0</temperature>
//    <humidity>0</humidity>
//    <YY>2024</YY>
//        <MM>06</MM>
//        <DD>02</DD>
//        <hh>14</hh>
//        <mm>30</mm>
//        <ss>45</ss>
//    </root>
   array.clear();
   array += "<root>\n";

   array += "<fun>";
   array += QString::number(data.fun);
   array += "</fun>\n";

   array += "<led>";
   array += QString::number(data.led);
   array += "</led>";

   array += "<angle>";
   array += QString::number(data.angle);
   array += "</angle>";

   array += "<temperature>";
   array += QString::number(data.temperature);
   array += "</temperature>";

   array += "<humidity>";
   array += QString::number(data.humidity);
   array += "</humidity>";

   array += "<year>";
   array += QString::number(date.YY);
   array += "</year>";

   array += "<mouth>";
   array += QString::number(date.MM);
   array += "</mouth>";

   array += "<day>";
   array += QString::number(date.DD);
   array += "</day>";

   array += "<hour>";
   array += QString::number(date.hh);
   array += "</hour>";

   array += "<minute>";
   array += QString::number(date.mm);
   array += "</minute>";

   array += "<second>";
   array += QString::number(date.ss);
   array += "</second>";

   array += "</root>";
}

void MainWindow::onTimeOut()
{
    //设置时间包
    QDate curDate = QDate::currentDate();
    QTime curTime = QTime::currentTime();
    date.YY = curDate.year();
    date.MM = curDate.month();
    date.DD = curDate.day();
    date.hh = curTime.hour();
    date.mm = curTime.minute();
    date.ss = curTime.second();

    QByteArray array;
    packing(date,packet,array);
    serial->write(array);
}
