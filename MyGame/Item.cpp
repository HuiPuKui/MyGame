#include "Item.h"

#include <cmath>

CItem::CItem() : m_iX(0), m_iY(0), m_iHeight(0), m_iWidth(0), m_iPrice(0), m_iKind(0), m_dSpeed(0), m_bVisible(true)
{

}

CItem::CItem(int X, int Y, int Height, int Width, int Price, int Kind, double Speed, bool Visible) : m_iX(X), m_iY(Y), m_iHeight(Height), m_iWidth(Width), m_iPrice(Price), m_iKind(Kind), m_dSpeed(Speed), m_bVisible(Visible)
{

}

CItem::~CItem()
{

}

int CItem::GetHeight() const
{
    return m_iHeight;
}

int CItem::GetWidth() const
{
    return m_iWidth;
}

int CItem::GetPrice() const
{
    return m_iPrice;
}

int CItem::GetKind() const
{
    return m_iKind;
}

double CItem::GetSpeed() const
{
    return m_dSpeed;
}

/**
 * @brief CItem::Detection
 * @param X
 * @param Y
 * @return
 * 检测是否碰撞
 */

bool CItem::Detection(const int X, const int Y)
{
    if (m_bVisible && abs(X - (m_iX + m_iWidth / 2)) < m_iWidth / 2 && abs(Y - (m_iY + m_iHeight / 2)) < m_iHeight / 2)
    {
        return true;
    }
    return false;
}
