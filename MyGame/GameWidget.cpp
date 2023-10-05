#include "GameWidget.h"
#include "ui_GameWidget.h"

#include <iostream>
#include <QTime>
#include <cmath>

#include <QPainter>
#include <QPen>
#include <QKeyEvent>

const double PI = acos(-1);

CGameWidget::CGameWidget(QWidget *parent) : QWidget(parent), ui(new Ui::CGameWidget)
{
    ui->setupUi(this);

    /// 音效

    m_SoundOfBackGround = new QSound(":/new/Music/BackGround.wav");
    m_SoundOfBackGround->setLoops(QSound::Infinite);

    m_SoundOfShoot = new QSound(":/new/Music/Shoot.wav");
    m_SoundOfShoot->setLoops(1);

    m_SoundOfGetFish = new QSound(":/new/Music/GetFish.wav");
    m_SoundOfGetFish->setLoops(1);

    m_qpbBack = ui->PBBack;
    m_cEndPage->setVisible(false);
    this->setWindowTitle("海底捕鱼小游戏");
    setFixedSize(1200, 800); // 设置窗口大小

    /// 初始化各种数据

    InitilizeTheData();
    InitilizeTheBackGround();
    InitiliedTheShip();
    InitiliedTheNumberOfItems(m_iTheNumberOfItems);

    connect(ui->PBPause, &QPushButton::clicked, this, &CGameWidget::PauseClicked);
    connect(ui->PBContinue, &QPushButton::clicked, this, &CGameWidget::ContinueClicked);
    connect(AutoBorn, &QTimer::timeout, this, &CGameWidget::AddItems);
    connect(SecondsTimer, &QTimer::timeout, this, &CGameWidget::GameTime);
    connect(PaintTimer, &QTimer::timeout, this, &CGameWidget::Rotate);
    connect(GrabTimer, &QTimer::timeout, this, &CGameWidget::Grab);
    connect(PaintTimer, &QTimer::timeout, [=]()
    {
        ui->LCDTotalTime->display(m_iTotalTime);
        if (m_iFasterTime != 0)
        {
            ui->label_4->setVisible(true);
            ui->LCDFasterTime->setVisible(true);
            ui->LCDFasterTime->display(m_iFasterTime);
        }
        else
        {
            ui->label_4->setVisible(false);
            ui->LCDFasterTime->setVisible(false);
        }
    });

    connect(m_cEndPage->GetPBNewGame(), &QPushButton::clicked, this, &CGameWidget::NewGame);
}

CGameWidget::~CGameWidget()
{
    delete ui;
}

void CGameWidget::paintEvent(QPaintEvent *)
{
    QPainter Painter(this);
    QPen Pen;
    Painter.translate(600, 55);
    Painter.rotate(m_dGrabAngle); //顺时针整体旋转90度
    Painter.translate(-600, -55); //使原点复原,因为旋转之后再画是根据新原点的相对位置画的
    Pen.setWidth(2);
    Painter.setPen(Pen);//旋转之后再画相当于把画布歪着放了，相对于桌面
    Painter.setRenderHint(QPainter::Antialiasing, true);
    Painter.drawLine(600, 55, 600, 85 + m_dGrabLength);//线的起点
    Painter.drawPixmap(568, 75 + m_dGrabLength, Pix);//绘图的起点
}

void CGameWidget::keyPressEvent(QKeyEvent *Event)
{
    int Key = Event->key();
    if (m_bGameIsStop == false && Key == Qt::Key_Enter && m_bIsRotating)
    {
        m_bNeedGrabing = true;
        m_bNeedRotating = false;
        m_SoundOfShoot->play();
    }
}

/**
 * @brief CGameWidget::InitilizeTheData
 * 初始化所有数据
 */

void CGameWidget::InitilizeTheData()
{
    m_iTotalTime = 120;
    m_iAddTime = 0;
    m_iFasterTime = 0; // 加速时间
    m_iIntervalOfAdd = 8; // 自动产生的间隔时间
    m_iTheMaxNumberOfAddItems = 3; // 自动产生的单次最大个数
    m_iTheNumberOfItems = 10; // 初始 item 数量
    m_dRate0 = 0.35;
    m_dRate1 = 0.3;
    m_dRate2 = 0.2;
    m_dRate3 = 0.07;
    m_dRate4 = 0.04;
    m_dRate5 = 0.04;

    m_bNeedRotating = true; // 旋转
    m_bIsRotating = true;
    m_bNeedGrabing = false; // 抓取
    m_bIsGrabing = false;
    m_bHasGrabingSomething = false; // 抓东西
    m_iGrabItem = 0;
    m_bGameIsStop = false;
    m_bHasFastGrab = false;
    m_bLableDisplayFlag = false;
    m_iScore = 0;
    m_dGrabLength = 0;
    m_dGrabSpeed = 2;

    ui->label_4->setVisible(false);
    ui->LCDScore->display("0");
    ui->LCDFasterTime->setVisible(false);

    m_dGrabAngle = 0;
    m_dGrabAngleChange = 0.5;
    m_iCurrentKind = 0;

    PaintTimer->start(15); // 图像 15ms 刷新一次
    GrabTimer->start(10);
    SecondsTimer->start(1000);
    AutoBorn->start(1000 * m_iIntervalOfAdd);

    ui->PBContinue->setVisible(false);
    ui->PBPause->setVisible(true);

    for (int i = 0; i < MyItems.size(); ++i)
    {
        delete MyItems[i];
        delete MyLables[i];
    }

    MyItems.clear();
    MyLables.clear();
}

/**
 * @brief CGameWidget::InitilizeTheBackGround
 * 初始化游戏背景
 */

void CGameWidget::InitilizeTheBackGround()
{
    this->setAutoFillBackground(true);
    QPalette Palette = this->palette();
    Palette.setBrush(QPalette::Window, QBrush(QPixmap(":/new/Picture/GameBackGround.jpg").scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(Palette);
}

void CGameWidget::InitiliedTheShip()
{
    ShipTimer->start(500);
    QImage *ShipImage = new QImage(":/new/Picture/Ship.png");
    QPixmap PixmapShip = QPixmap::fromImage(ShipImage->scaled(70, 70, Qt::KeepAspectRatio));
    LabelShip->setPixmap(PixmapShip); //加载船
    LabelShip->move(570, 5);

    connect(ShipTimer, &QTimer::timeout, [=]()
    {
        static int ShipState = 1;
        if (ShipState == 1)
        {
            LabelShip->move(567, 5);
        }
        else
        {
            LabelShip->move(570, 5);
        }
        ShipState ^= 1;
    });
}

void CGameWidget::InitiliedTheNumberOfItems(int Number)
{
    MyItems.clear();
    MyLables.clear();
    CreateItems(Number);
}

void CGameWidget::CreateItems(int Number)
{
    QTime Time = QTime::currentTime();
    qsrand(Time.msec() + Time.second() * 1000);
    for (int i = 1; i <= Number; ++i)
    {
        int RandNumber = qrand() % 100 + 1;
        QImage Image;
        int X = 0, Y = 0, Height = 0, Width = 0, Price = 0, Kind = 0;
        double Speed = 0;
        bool Visible = false;

        X = qrand() % 1100 + 10;
        Y = qrand() % 630 + 70;

        QString PicturePath;
        if (RandNumber >= 1 && RandNumber <= 35)
        {
            Height = 80, Width = 50, Price = 10, Kind = 0, Speed = 10, Visible = true, PicturePath = ":/new/Picture/SmallFish.png";
        }
        else if (RandNumber >= 36 && RandNumber <= 65)
        {
            Height = 85, Width = 60, Price = 20, Kind = 1, Speed = 8, Visible = true, PicturePath = ":/new/Picture/MiddleFish.png";
        }
        else if (RandNumber >= 66 && RandNumber <= 85)
        {
            Height = 93, Width = 93, Price = 30, Kind = 2, Speed = 5, Visible = true, PicturePath = ":/new/Picture/BigFish.png";
        }
        else if (RandNumber >= 86 && RandNumber <= 92)
        {
            Height = 85, Width = 60, Price = 0, Kind = 3, Speed = 8, Visible = true, PicturePath = ":/new/Picture/FastFish.png";
        }
        else if (RandNumber >= 93 && RandNumber <= 96)
        {
            Height = 85, Width = 85, Price = 0, Kind = 4, Speed = 8, Visible = true, PicturePath = ":/new/Picture/TimeFish.png";
        }
        else if (RandNumber >= 97 && RandNumber <= 100)
        {
            Height = 100, Width = 100, Price = -100, Kind = 5, Speed = 100, Visible = true, PicturePath = ":/new/Picture/Shark.png";
        }
        MyItems.push_back(new CItem(X, Y, Height, Width, Price, Kind, Speed, Visible));
        Image.load(PicturePath);
        QPixmap Pixmap = QPixmap::fromImage(Image.scaled(Height, Width, Qt::KeepAspectRatio));
        QLabel *MyLabel = new QLabel(this);
        MyLabel->setPixmap(Pixmap);
        MyLabel->move(X, Y);
        MyLabel->setVisible(Visible);
        MyLables.push_back(MyLabel);
    }
}

void CGameWidget::GamePause()
{
    PaintTimer->stop();
    GrabTimer->stop();
    ShipTimer->stop();
    AutoBorn->stop();
    SecondsTimer->stop();
}

void CGameWidget::GameContinue()
{
    PaintTimer->start(15);
    GrabTimer->start(10);
    SecondsTimer->start(1000);
    AutoBorn->start(1000 * m_iIntervalOfAdd);
    ShipTimer->start(500);
}

void CGameWidget::PauseClicked()
{
    GamePause();
    ui->PBPause->setVisible(false);
    ui->PBContinue->setVisible(true);
}

void CGameWidget::ContinueClicked()
{
    GameContinue();
    ui->PBContinue->setVisible(false);
    ui->PBPause->setVisible(true);
}

void CGameWidget::AddItems()
{
    QTime Time = QTime::currentTime();
    qsrand(Time.msec() + Time.second() * 1000);
    int Number = rand() % m_iTheMaxNumberOfAddItems + 1;
    CreateItems(Number);
}

void CGameWidget::GameTime()
{
    --m_iTotalTime;
    if (m_iTotalTime != 0)
    {
        m_iTotalTime = m_iTotalTime + m_iAddTime;
        m_iAddTime = 0;
        m_cEndPage->setVisible(false);
    }

    if (m_iFasterTime != 0)
    {
        --m_iFasterTime;
    }

    if (m_iTotalTime < 0)
    {
        m_cEndPage->setVisible(true);
        this->setVisible(false);
        QString LabelString = "您的分数：";
        LabelString.append(QString::number(m_iScore));
        m_cEndPage->GetScore()->setText(LabelString);
        GamePause();
    }
}

void CGameWidget::NewGame()
{
    GameContinue();
    InitilizeTheData();
    InitiliedTheNumberOfItems(m_iTheNumberOfItems);
    this->setVisible(true);
    m_cEndPage->setVisible(false);
}

void CGameWidget::Rotate()
{
    m_bGameIsStop = false;
    if (m_bNeedRotating == true)
    {
        m_bIsRotating = true;
        m_bIsGrabing = false;
        if (m_dGrabAngle >= 85 || m_dGrabAngle <= -85)
        {
            m_dGrabAngleChange = -m_dGrabAngleChange;
        }
        m_dGrabAngle = m_dGrabAngle + m_dGrabAngleChange;
        update();
    }
}

void CGameWidget::Grab()
{
    if (m_iFasterTime == 0)
    {
        m_dGrabSpeed = 2;
    }
    else
    {
        m_dGrabSpeed = 5;
    }

    static double LengthChange = m_dGrabSpeed;
    int Gx = 600 - (m_dGrabLength + 60) * sin(m_dGrabAngle * PI / 180);
    int Gy = 55 + (m_dGrabLength + 60) * cos(m_dGrabAngle * PI / 180);

    if (m_bNeedGrabing == true) // 需要抓取动作
    {
        m_bIsRotating = false;
        m_bIsGrabing = true;
        //未抓到的越界状态
        if ((Gx < 30 || Gx > 1170 || Gy > 770) && m_bHasGrabingSomething == false) //边缘控制
        {
            LengthChange = -m_dGrabSpeed * 5;//一般状态，空手回去速度快
            m_dGrabLength = m_dGrabLength + LengthChange;
        }
        //未抓到的返回完毕状态
        else if (m_dGrabLength < 0 && m_bHasGrabingSomething == false)
        {
            m_bNeedGrabing = false;
            m_dGrabLength = 0;
            m_bNeedRotating = true;
            LengthChange = m_dGrabSpeed;//一般状态,没抓到东西回去快一点
        }
        //未抓东西的普通状态
        else if (m_bHasGrabingSomething == false)
        {
            if(LengthChange > 0)
            {
                 LengthChange = m_dGrabSpeed;//去的时候根据当前速度修正
            }
            m_dGrabLength = m_dGrabLength + LengthChange;//一般状态
            for (int i = 0; i < MyItems.size(); ++i)
            {
                if (MyItems[i]->Detection(Gx, Gy))
                {
                    m_bHasGrabingSomething = true;
                    m_iGrabItem = i;

                    LengthChange = -m_dGrabSpeed * MyItems[m_iGrabItem]->GetSpeed() * 1.0 / 8;
                    m_dGrabLength = m_dGrabLength + LengthChange;
                    break;
                }
            }
        }
        //抓了东西的普通状态
        else if (m_dGrabLength >= 0 && m_bHasGrabingSomething == true)
        {
            MyLables[m_iGrabItem]->move(Gx - MyItems[m_iGrabItem]->GetWidth() / 2 - sin(m_dGrabAngle * PI / 180) * 10 ,Gy - MyItems[m_iGrabItem]->GetHeight() / 2 + cos(m_dGrabAngle * PI / 180) * 10);// 中心点挂碰撞点
            m_dGrabLength = m_dGrabLength + LengthChange;
        }
        //抓了东西的返回完毕状态
        else if (m_dGrabLength < 0 && m_bHasGrabingSomething == true)
        {
            m_SoundOfGetFish->play();
            m_iScore = m_iScore + MyItems.at(m_iGrabItem)->GetPrice();
            m_iCurrentKind = MyItems.at(m_iGrabItem)->GetKind();
            MyLables.at(m_iGrabItem)->setVisible(false);
            delete MyLables.at(m_iGrabItem);
            delete MyItems.at(m_iGrabItem);
            MyLables.erase(MyLables.begin()+m_iGrabItem);
            MyItems.erase(MyItems.begin()+m_iGrabItem);

            m_bHasGrabingSomething = false;
            m_bNeedGrabing = false;
            m_dGrabLength = 0;
            m_bNeedRotating = true;
            LengthChange = m_dGrabSpeed;//恢复方向,恢复因为抓取物品影响的速度

            ui->LCDScore->display(m_iScore);//抓取之后的分数变化
            switch (m_iCurrentKind)
            {
            case 3:
            {
                m_iFasterTime = m_iFasterTime + 20;
                break;
            }
            case 4:
            {
                m_iAddTime = 30;
                break;
            }
            default:break;
            }
        }
        update();
    }
}


