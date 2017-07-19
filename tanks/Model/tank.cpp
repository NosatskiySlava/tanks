#include "tank.h"

#include <gameproperties.h>
#include <memory>

#include <Model/bullet.h>

Tank::Tank(QObject* p)
    : QObject(p)
    , m_dir(Common::EDirection::UP)
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
    m_dir = Common::EDirection::UP;
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
    m_dir = Common::EDirection::DOWN;
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
    m_dir = Common::EDirection::LEFT;
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
    m_dir = Common::EDirection::RIGHT;
    if (m_pos.x == (GameProperties::fieldWidth() - GameProperties::tankImageSize())) {
        emit movedRight();
        return;
    }

    ++m_pos.x;
    emit xChanged();
    emit movedRight();
}

void Tank::makeShot()
{
    std::shared_ptr<Bullet> bullet(new Bullet(m_pos, m_dir));
    emit shot(bullet);
}

