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

    void StartGame();
private:
    Ui::CMainWindow *ui;
    CGameWidget *m_cGameWidget;
    QSound *m_qBackGround;
};

#endif // _MAINWINDOW_H__
