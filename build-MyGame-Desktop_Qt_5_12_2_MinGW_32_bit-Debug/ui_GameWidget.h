/********************************************************************************
** Form generated from reading UI file 'GameWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGameWidget
{
public:
    QPushButton *PBBack;
    QLCDNumber *LCDScore;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLCDNumber *LCDTotalTime;
    QLCDNumber *LCDFasterTime;
    QPushButton *PBPause;
    QPushButton *PBContinue;

    void setupUi(QWidget *CGameWidget)
    {
        if (CGameWidget->objectName().isEmpty())
            CGameWidget->setObjectName(QString::fromUtf8("CGameWidget"));
        CGameWidget->resize(1200, 800);
        PBBack = new QPushButton(CGameWidget);
        PBBack->setObjectName(QString::fromUtf8("PBBack"));
        PBBack->setGeometry(QRect(680, 10, 93, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setBold(true);
        font.setWeight(75);
        PBBack->setFont(font);
        LCDScore = new QLCDNumber(CGameWidget);
        LCDScore->setObjectName(QString::fromUtf8("LCDScore"));
        LCDScore->setGeometry(QRect(60, 10, 81, 41));
        label = new QLabel(CGameWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 72, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_3 = new QLabel(CGameWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1010, 10, 81, 41));
        label_3->setFont(font1);
        label_4 = new QLabel(CGameWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(900, 10, 91, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        LCDTotalTime = new QLCDNumber(CGameWidget);
        LCDTotalTime->setObjectName(QString::fromUtf8("LCDTotalTime"));
        LCDTotalTime->setGeometry(QRect(1100, 10, 81, 41));
        LCDFasterTime = new QLCDNumber(CGameWidget);
        LCDFasterTime->setObjectName(QString::fromUtf8("LCDFasterTime"));
        LCDFasterTime->setGeometry(QRect(910, 30, 64, 23));
        PBPause = new QPushButton(CGameWidget);
        PBPause->setObjectName(QString::fromUtf8("PBPause"));
        PBPause->setGeometry(QRect(790, 10, 93, 28));
        PBPause->setFont(font);
        PBContinue = new QPushButton(CGameWidget);
        PBContinue->setObjectName(QString::fromUtf8("PBContinue"));
        PBContinue->setGeometry(QRect(790, 10, 93, 28));
        PBContinue->setFont(font);

        retranslateUi(CGameWidget);

        QMetaObject::connectSlotsByName(CGameWidget);
    } // setupUi

    void retranslateUi(QWidget *CGameWidget)
    {
        CGameWidget->setWindowTitle(QApplication::translate("CGameWidget", "Form", nullptr));
        PBBack->setText(QApplication::translate("CGameWidget", "\350\277\224\345\233\236\351\246\226\351\241\265", nullptr));
        label->setText(QApplication::translate("CGameWidget", "\345\210\206\346\225\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("CGameWidget", "\345\211\251\344\275\231\346\227\266\351\227\264\357\274\232", nullptr));
        label_4->setText(QApplication::translate("CGameWidget", "\345\211\251\344\275\231\345\212\240\351\200\237\346\227\266\351\225\277\357\274\232", nullptr));
        PBPause->setText(QApplication::translate("CGameWidget", "\346\232\202\345\201\234", nullptr));
        PBContinue->setText(QApplication::translate("CGameWidget", "\347\273\247\347\273\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGameWidget: public Ui_CGameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
