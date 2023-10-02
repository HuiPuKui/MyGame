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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGameWidget
{
public:
    QPushButton *PBBack;

    void setupUi(QWidget *CGameWidget)
    {
        if (CGameWidget->objectName().isEmpty())
            CGameWidget->setObjectName(QString::fromUtf8("CGameWidget"));
        CGameWidget->resize(776, 502);
        PBBack = new QPushButton(CGameWidget);
        PBBack->setObjectName(QString::fromUtf8("PBBack"));
        PBBack->setGeometry(QRect(370, 10, 93, 28));

        retranslateUi(CGameWidget);

        QMetaObject::connectSlotsByName(CGameWidget);
    } // setupUi

    void retranslateUi(QWidget *CGameWidget)
    {
        CGameWidget->setWindowTitle(QApplication::translate("CGameWidget", "Form", nullptr));
        PBBack->setText(QApplication::translate("CGameWidget", "\350\277\224\345\233\236\351\246\226\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGameWidget: public Ui_CGameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
