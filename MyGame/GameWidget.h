#ifndef _GAMEWIDGET_H__
#define _GAMEWIDGET_H__

#include <QWidget>
#include <QPushButton>

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

public:
    QPushButton *m_qpbBack; // 返回首页按钮

private:
    Ui::CGameWidget *ui;
};

#endif // _GAMEWIDGET_H__
