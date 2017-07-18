#include "tank.h"

#include <gameproperties.h>

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
    if (m_pos.y == 0) {
        emit movedUp();
        return;
    }

    --m_pos.y;
    emit yChanged();
    emit movedUp();
}

void Tank::moveDown()
{
    if (m_pos.y == GameProperties::fieldHeight() - GameProperties::tankImageSize()) {
        emit movedDown();
        return;
    }

    ++m_pos.y;
    emit yChanged();
    emit movedDown();
}

void Tank::moveLeft()
{
    if (m_pos.x == 0) {
        emit movedLeft();
        return;
    }

    --m_pos.x;
    emit xChanged();
    emit movedLeft();
}

void Tank::moveRight()
{
    if (m_pos.x == (GameProperties::fieldWidth() - GameProperties::tankImageSize())) {
        emit movedRight();
        return;
    }

    ++m_pos.x;
    emit xChanged();
    emit movedRight();
}

