#ifndef _GAMEWIDGET_H__
#define _GAMEWIDGET_H__

#include <QWidget>
#include <QPushButton>
#include <vector>
#include <QSound>
#include <QLabel>
#include <QTimer>

#include "Item.h"
#include "EndPage.h"

namespace Ui
{
    class CGameWidget;
}

class CGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CGameWidget(QWidget *parent = nullptr);
    ~CGameWidget();

    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent*);

private:
    void InitilizeTheData();
    void InitilizeTheBackGround();
    void InitiliedTheShip();
    void InitiliedTheNumberOfItems(int);

    void CreateItems(int);
    void GamePause();
    void GameContinue();
    void PauseClicked();
    void ContinueClicked();
    void AddItems();
    void GameTime();
    void NewGame();

    void Rotate();
    void Grab();
public:
    QPushButton *m_qpbBack; // 返回首页按钮

private:
    Ui::CGameWidget *ui;

    CEndPage *m_cEndPage = new CEndPage();
    QSound *m_SoundOfBackGround;
    QSound *m_SoundOfShoot;
    QSound *m_SoundOfGetFish;

    int m_iTotalTime; // 剩余时间
    int m_iAddTime; // 奖励时间
    int m_iFasterTime; // 加速时间
    int m_iIntervalOfAdd; // 自动产生的间隔时间
    int m_iTheMaxNumberOfAddItems; // 自动产生的单次最大个数
    int m_iTheNumberOfItems; // 初始 item 数量
    double m_dRate0;
    double m_dRate1;
    double m_dRate2;
    double m_dRate3;
    double m_dRate4;
    double m_dRate5;

    bool m_bNeedRotating; // 旋转
    bool m_bIsRotating;
    bool m_bNeedGrabing; // 抓取
    bool m_bIsGrabing;
    bool m_bHasGrabingSomething; // 抓东西
    int m_iGrabItem;
    bool m_bGameIsStop;
    bool m_bHasFastGrab;
    bool m_bLableDisplayFlag;
    int m_iScore;
    double m_dGrabLength;
    double m_dGrabSpeed;

    double m_dGrabAngle;
    double m_dGrabAngleChange;
    int m_iCurrentKind;

    std::vector<CItem*> MyItems;
    std::vector<QLabel*> MyLables;

    QLabel *LabelShip = new QLabel(this);
    QPixmap Pix = QPixmap(":/new/Picture/Gouzi.png");

    QTimer *PaintTimer = new QTimer(this);
    QTimer *GrabTimer = new QTimer(this);
    QTimer *ShipTimer = new QTimer(this);
    QTimer *AutoBorn = new QTimer(this);
    QTimer *SecondsTimer = new QTimer(this);
};

#endif // _GAMEWIDGET_H__
