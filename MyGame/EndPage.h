#ifndef ENDPAGE_H
#define ENDPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class CEndPage;
}

class CEndPage : public QWidget
{
    Q_OBJECT

public:
    explicit CEndPage(QWidget *parent = nullptr);
    ~CEndPage();

    QPushButton *GetPBNewGame();
    QLabel *GetScore();

private:
    Ui::CEndPage *ui;

    QPushButton *m_qPBPtrNewGame;
    QPushButton *m_qPBPtrExitGame;
    QLabel *m_qLPtrScore;
    QLabel *m_qLPtrLabel;
};

#endif // ENDPAGE_H
