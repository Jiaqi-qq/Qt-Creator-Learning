/********************************************************************************
** Form generated from reading UI file 'tcpform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPFORM_H
#define UI_TCPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpForm
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pb1;
    QPushButton *pb2;
    QPushButton *pb3;

    void setupUi(QWidget *TcpForm)
    {
        if (TcpForm->objectName().isEmpty())
            TcpForm->setObjectName(QString::fromUtf8("TcpForm"));
        TcpForm->resize(729, 419);
        textBrowser = new QTextBrowser(TcpForm);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(340, 60, 281, 241));
        pb1 = new QPushButton(TcpForm);
        pb1->setObjectName(QString::fromUtf8("pb1"));
        pb1->setGeometry(QRect(90, 110, 80, 20));
        pb2 = new QPushButton(TcpForm);
        pb2->setObjectName(QString::fromUtf8("pb2"));
        pb2->setGeometry(QRect(90, 160, 80, 20));
        pb3 = new QPushButton(TcpForm);
        pb3->setObjectName(QString::fromUtf8("pb3"));
        pb3->setGeometry(QRect(90, 210, 80, 20));

        retranslateUi(TcpForm);

        QMetaObject::connectSlotsByName(TcpForm);
    } // setupUi

    void retranslateUi(QWidget *TcpForm)
    {
        TcpForm->setWindowTitle(QCoreApplication::translate("TcpForm", "Form", nullptr));
        pb1->setText(QCoreApplication::translate("TcpForm", "1", nullptr));
        pb2->setText(QCoreApplication::translate("TcpForm", "2", nullptr));
        pb3->setText(QCoreApplication::translate("TcpForm", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpForm: public Ui_TcpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPFORM_H
