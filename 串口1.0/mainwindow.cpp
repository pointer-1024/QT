#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("串口");
    ui->checkBox->setEnabled(false);
    connect(serial,&QSerialPort::readyRead,this,&MainWindow::data_receive);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->comboBox->clear();

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        QSerialPort _com;
        _com.setPort(info);
        if(_com.portName() == serial->portName() or _com.open(QIODevice::ReadWrite)){
            ui->comboBox->addItem(info.portName());
            _com.close();
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!serial->isOpen()){
        serial->setPortName(ui->comboBox->currentText());
        serial->setBaudRate(ui->comboBox_2->currentText().toLong());

        switch (ui->comboBox_3->currentIndex()) {
            case 0: serial->setStopBits(QSerialPort::OneStop); break;
            case 1: serial->setStopBits(QSerialPort::TwoStop); break;
            case 2: serial->setStopBits(QSerialPort::OneAndHalfStop); break;
        }

        switch(ui->comboBox_4->currentText().toLong()){
            case 5: serial->setDataBits(QSerialPort::Data5); break;
            case 6: serial->setDataBits(QSerialPort::Data6); break;
            case 7: serial->setDataBits(QSerialPort::Data7); break;
            case 8: serial->setDataBits(QSerialPort::Data8); break;
        }

        switch (ui->comboBox_5->currentIndex()) {
            case 0: serial->setParity(QSerialPort::NoParity); break;
            case 1: serial->setParity(QSerialPort::EvenParity); break;
            case 2: serial->setParity(QSerialPort::OddParity); break;
        }

        serial->open(QIODevice::ReadWrite);
        ui->checkBox->setChecked(true);
        ui->pushButton_2->setText("关闭串口");
    } else {
        serial->close();
        ui->checkBox->setChecked(false);
        ui->pushButton_2->setText("打开串口");
    }


}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(!serial->isOpen()){
        return;
    }

    QString str = ui->textEdit->toPlainText();
    QStringList list = str.split("\n");

    for(int i = 0; i < list.size(); i++){
        if(list[i] == "") continue;

        list[i] += "\r\n";
        serial->write(list[i].toLocal8Bit());
    }
}

void MainWindow::data_receive()
{
    QByteArray buffer = serial->readAll();
    QString str = "";
    str += str.fromLocal8Bit(buffer);
    ui->textBrowser->moveCursor(QTextCursor::End);
    ui->textBrowser->insertPlainText(str);
    ui->textBrowser->moveCursor(QTextCursor::End);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textBrowser->clear();
}
