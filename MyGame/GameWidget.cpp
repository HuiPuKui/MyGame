#include "GameWidget.h"
#include "ui_GameWidget.h"

CGameWidget::CGameWidget(QWidget *parent) : QWidget(parent), ui(new Ui::CGameWidget)
{
    ui->setupUi(this);

    m_qpbBack = ui->PBBack;

    setFixedSize(1200, 800); // 设置窗口大小
}

CGameWidget::~CGameWidget()
{
    delete ui;
}
