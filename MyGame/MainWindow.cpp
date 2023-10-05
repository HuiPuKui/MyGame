#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "GameWidget.h"

#include <QSound>

/**
 * @brief CMainWindow::CMainWindow
 * @param parent
 *
 * 页面初始化
 */

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("海底捕鱼小游戏");

    QPalette paletteOfLable;
    paletteOfLable.setColor(QPalette::WindowText,Qt::yellow);
    ui->label->setPalette(paletteOfLable);

    this->setFixedSize(QSize(1200,800));
    this->setAutoFillBackground(true);
    QPalette paletteOfWindow = this->palette();
    paletteOfWindow.setBrush(QPalette::Window, QBrush(QPixmap(":/new/Picture/BackGround.png").scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));             // 使用平滑的缩放方式
    this->setPalette(paletteOfWindow);

    m_qBackGround = new QSound(":/new/Music/BackGround.wav");
    m_qBackGround->play();

    connect(ui->PBStartGame, &QPushButton::clicked, this, &CMainWindow::StartGame);
    connect(ui->PBExitGame, &QPushButton::clicked, this, &CMainWindow::close);
}

/**
 * @brief CMainWindow::~CMainWindow
 * 析构
 */

CMainWindow::~CMainWindow()
{
    delete ui;
}

/**
 * @brief CMainWindow::StartGame
 * 点击开始游戏
 */

void CMainWindow::StartGame()
{
    m_qBackGround->stop();
    m_cGameWidget = new CGameWidget();
    connect(m_cGameWidget->m_qpbBack, &QPushButton::clicked, [=]()
    {
        m_cGameWidget->setVisible(false);   // 关闭游戏界面
        delete m_cGameWidget;               // 前面申请的内存，在返回时记得析构掉
        m_qBackGround->play();              // 背景音乐
        this->setVisible(true);             // 打开主页面
    });
    m_cGameWidget->setVisible(true);        // 打开游戏界面
    this->setVisible(false);                // 关掉主页面
}
