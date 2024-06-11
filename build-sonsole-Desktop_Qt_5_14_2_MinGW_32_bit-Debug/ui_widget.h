/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QTextEdit *textEdit;
    QGroupBox *groupBox_6;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 530, 81, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("border:1px solid black"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 500, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("border:1px solid black"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 500, 91, 31));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 530, 91, 31));
        pushButton_2->setFont(font);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(170, 470, 111, 101));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(410, 470, 111, 101));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(420, 530, 91, 31));
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 500, 91, 31));
        pushButton_4->setFont(font);
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(660, 470, 111, 101));
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(670, 530, 91, 31));
        pushButton_5->setFont(font);
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(670, 500, 91, 31));
        pushButton_6->setFont(font);
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 440, 781, 151));
        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 10, 321, 431));
        textEdit = new QTextEdit(groupBox_5);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 301, 411));
        groupBox_6 = new QGroupBox(Widget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(350, 10, 421, 431));
        textEdit_2 = new QTextEdit(groupBox_6);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 20, 421, 411));
        textEdit_2->setReadOnly(true);
        groupBox_6->raise();
        groupBox_5->raise();
        groupBox_4->raise();
        groupBox->raise();
        label_2->raise();
        label_3->raise();
        pushButton->raise();
        pushButton_2->raise();
        groupBox_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        groupBox_3->raise();
        pushButton_5->raise();
        pushButton_6->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\212\240\347\203\255\345\231\250</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\351\243\216\346\211\207</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\274\200", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\274\200", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\345\244\247\346\243\2321", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\345\244\247\346\243\2322", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\274\200", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\345\274\200", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\345\244\247\346\243\2323", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "\345\274\200", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "\345\274\200", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "\346\223\215\346\216\247\345\217\260", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Widget", "\346\230\276\347\244\272", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Widget", "\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
