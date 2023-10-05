/********************************************************************************
** Form generated from reading UI file 'EndPage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDPAGE_H
#define UI_ENDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CEndPage
{
public:
    QLabel *label;
    QPushButton *PBNewGame;
    QPushButton *PBExitGame;
    QLabel *LabelScore;

    void setupUi(QWidget *CEndPage)
    {
        if (CEndPage->objectName().isEmpty())
            CEndPage->setObjectName(QString::fromUtf8("CEndPage"));
        CEndPage->resize(1200, 800);
        label = new QLabel(CEndPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 130, 431, 161));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(72);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        PBNewGame = new QPushButton(CEndPage);
        PBNewGame->setObjectName(QString::fromUtf8("PBNewGame"));
        PBNewGame->setGeometry(QRect(190, 440, 291, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        PBNewGame->setFont(font1);
        PBExitGame = new QPushButton(CEndPage);
        PBExitGame->setObjectName(QString::fromUtf8("PBExitGame"));
        PBExitGame->setGeometry(QRect(670, 440, 291, 101));
        PBExitGame->setFont(font1);
        LabelScore = new QLabel(CEndPage);
        LabelScore->setObjectName(QString::fromUtf8("LabelScore"));
        LabelScore->setGeometry(QRect(400, 320, 401, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(28);
        LabelScore->setFont(font2);

        retranslateUi(CEndPage);

        QMetaObject::connectSlotsByName(CEndPage);
    } // setupUi

    void retranslateUi(QWidget *CEndPage)
    {
        CEndPage->setWindowTitle(QApplication::translate("CEndPage", "Form", nullptr));
        label->setText(QApplication::translate("CEndPage", "\346\270\270\346\210\217\347\273\223\346\235\237\357\274\201", nullptr));
        PBNewGame->setText(QApplication::translate("CEndPage", "\346\226\260\346\270\270\346\210\217", nullptr));
        PBExitGame->setText(QApplication::translate("CEndPage", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        LabelScore->setText(QApplication::translate("CEndPage", "\346\202\250\347\232\204\345\210\206\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CEndPage: public Ui_CEndPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDPAGE_H
