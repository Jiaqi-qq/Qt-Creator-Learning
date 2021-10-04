/********************************************************************************
** Form generated from reading UI file 'udpform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPFORM_H
#define UI_UDPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UdpForm
{
public:
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *UdpForm)
    {
        if (UdpForm->objectName().isEmpty())
            UdpForm->setObjectName(QString::fromUtf8("UdpForm"));
        UdpForm->resize(721, 437);
        pushButton = new QPushButton(UdpForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 90, 80, 20));
        textBrowser = new QTextBrowser(UdpForm);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(240, 50, 301, 221));

        retranslateUi(UdpForm);

        QMetaObject::connectSlotsByName(UdpForm);
    } // setupUi

    void retranslateUi(QWidget *UdpForm)
    {
        UdpForm->setWindowTitle(QCoreApplication::translate("UdpForm", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("UdpForm", "\350\277\233\350\241\214\345\271\277\346\222\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UdpForm: public Ui_UdpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPFORM_H
