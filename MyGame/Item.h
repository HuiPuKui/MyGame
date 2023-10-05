#ifndef _ITEM_H__
#define _ITEM_H__

class CItem
{
public:
    CItem();
    CItem(int, int, int, int, int, int, double, bool);
    ~CItem();

    int GetHeight() const;
    int GetWidth() const;
    int GetPrice() const;
    int GetKind() const;
    double GetSpeed() const;

    bool Detection(const int, const int);   // 检测是否会碰撞

private:
    int m_iX;       // 坐标 x
    int m_iY;       // 坐标 y
    int m_iHeight;  // 物体高
    int m_iWidth;   // 物体宽
    int m_iPrice;   // 物体价值
    int m_iKind;    // 状态
    double m_dSpeed;// 速度
    bool m_bVisible;// 显示
};

#endif // _ITEM_H__
