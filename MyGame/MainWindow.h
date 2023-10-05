#ifndef _MAINWINDOW_H__
#define _MAINWINDOW_H__

#include <QMainWindow>
#include <QSound>

#include "GameWidget.h"

/**
 * 主页面
 */

namespace Ui
{
    class CMainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

private:
    void StartGame();

private:
    Ui::CMainWindow *ui;
    CGameWidget *m_cGameWidget;     // 游戏界面
    QSound *m_qBackGround;          // 背景音乐
};

#endif // _MAINWINDOW_H__
