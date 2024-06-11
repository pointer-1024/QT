#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QHostAddress>
#include<QString>
#include<QMessageBox>
#include<QTimer>
#include<QDebug>
#include<cmath>
#include<QStringList>

struct info{
    bool fun; //风扇
    bool heater; //加热器
    int humi; //湿度
    int temp; //温度
};

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    info shed[3] = {{false,false,60,18},{false,false,50,18},{false,false,60,24}};
private:
    Ui::Widget *ui;
    QTcpServer *server;
    QTimer *timer;
    QTcpSocket* socket;
    int currentTime;

    std::pair<int, int> simulateEnvironment1(int time);
    std::pair<int, int> simulateEnvironment2(int time);
    std::pair<int, int> simulateEnvironment3(int time);
    void update();
    QString strSpilt(const QString &str);
private slots:
    void newClientHandler();
    void checkServerStatus();
    void readClientData(const QString &str);
};
#endif // WIDGET_H
