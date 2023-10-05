#include "EndPage.h"
#include "ui_EndPage.h"

CEndPage::CEndPage(QWidget *parent) : QWidget(parent), ui(new Ui::CEndPage)
{
    ui->setupUi(this);

    this->setWindowTitle("海底捕鱼小游戏");
    this->setFixedSize(1200, 800);

    m_qPBPtrNewGame = ui->PBNewGame;
    m_qPBPtrExitGame = ui->PBExitGame;
    m_qLPtrScore = ui->LabelScore;
    m_qLPtrLabel = ui->label;

    /// 放置背景

    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
    QBrush(QPixmap(":/new/Picture/BackGround.png").scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    connect(ui->PBExitGame, &QPushButton::clicked, this, &QWidget::close);
}

CEndPage::~CEndPage()
{
    delete ui;
}

QPushButton *CEndPage::GetPBNewGame()
{
    return m_qPBPtrNewGame;
}

QLabel *CEndPage::GetScore()
{
    return m_qLPtrScore;
}
