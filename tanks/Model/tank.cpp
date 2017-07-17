#include "tank.h"

Tank::Tank(QObject* p):
QObject(p)
{
}

int Tank::x() const {
    return m_pos.x;
}

int Tank::y() const {
    return m_pos.y;
}

void Tank::moveUp()
{
    --m_pos.y;
    emit yChanged();
    emit movedUp();
}

void Tank::moveDown()
{
    ++m_pos.y;
    emit yChanged();
    emit movedDown();
}

void Tank::moveLeft()
{
    --m_pos.x;
    emit xChanged();
    emit movedLeft();
}

void Tank::moveRight()
{
    ++m_pos.x;
    emit xChanged();
    emit movedRight();
}

