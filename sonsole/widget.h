#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QMessageBox>
#include<QString>
#include<QHostAddress>
#include<QTcpSocket>
#include<QTimer>
#include<QtCharts>
#include<QChartView>
#include<QSplineSeries>
#include <QTextBrowser>
#include <QPixmap>
#include <QImage>
#include <QVBoxLayout>
#include<QDateTime>
#include<iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //按钮检测
    bool buttonCheck1 = false;
    bool buttonCheck2 = false;
    bool buttonCheck3 = false;
    bool buttonCheck4 = false;
    bool buttonCheck5 = false;
    bool buttonCheck6 = false;

private:
    QTcpSocket *socket;
    Ui::Widget *ui;
    QTimer *timer;
    QTimer *timer2;
    QDateTime dt;

private slots:
    void clientConnect();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};
#endif // WIDGET_H
