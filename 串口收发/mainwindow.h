#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QPixmap>
#include<QPaintEvent>
#include<QSerialPort>
#include<QSerialPortInfo>
#include<QString>
#include<QDomDocument>
#include<QMessageBox>
#include<QDebug>
#include<QTime>
#include<QDate>
#include<QVector>
#include<QStringList>
#include<QTimer>
#include<QXmlStreamReader>

//数据包
struct dataPacket{
    bool fun;
    bool led;
    unsigned int angle;
    unsigned int temperature;
    unsigned int humidity;
};

//时间包
struct datePacket{
    unsigned int YY;
    unsigned char MM;
    unsigned char DD;
    unsigned char hh;
    unsigned char mm;
    unsigned char ss;
};

//标签头
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort *serial;
    dataPacket packet;
    datePacket date;
    QTimer *timer;


    //解包
    void unpacking(dataPacket &data,const QByteArray& array);
    //打包
    void packing(const datePacket &date,const dataPacket &data,QByteArray& array);
protected:
    void paintEvent(QPaintEvent* event) override;

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receive();

    void on_pushButton_3_clicked();

    void onTimeOut();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
