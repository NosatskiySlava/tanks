#include "bullet.h"
#include "tank.h"

#include <Common/gameproperties.h>

#include <memory>

namespace {
    Position calculateBulletPosition(const Position& i_tankPos, Common::EDirection::Type i_tankDirection) {
        Position result;

        switch (i_tankDirection) {
        case Common::EDirection::UP :
            result.x = i_tankPos.x + GameProperties::tankImageSize()/2 - 4;
            result.y = i_tankPos.y - 4;
            break;
        case Common::EDirection::DOWN :
            result.x = i_tankPos.x + GameProperties::tankImageSize()/2 - 4;
            result.y = i_tankPos.y + GameProperties::tankImageSize();
            break;
        case Common::EDirection::LEFT :
            result.x = i_tankPos.x -  4;
            result.y = i_tankPos.y + GameProperties::tankImageSize()/2 - GameProperties::bulletIconHeight()/2 - 3;
            break;
        case Common::EDirection::RIGHT :
            result.x = i_tankPos.x + GameProperties::tankImageSize();
            result.y = i_tankPos.y + GameProperties::tankImageSize()/2 - GameProperties::bulletIconHeight()/2 - 3;
            break;
        default:
            break;
        }

        return result;
    }
}

Tank::Tank(QObject* p)
    : QObject(p)
    , m_dir(Common::EDirection::UP)
{
}

Tank::Tank(const Position& i_pos, Common::EDirection::Type i_dir, QObject* parent)
    : QObject(parent)
    , m_pos(i_pos)
    , m_dir(i_dir)
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
    std::shared_ptr<Bullet> bullet(new Bullet(calculateBulletPosition(m_pos, m_dir), m_dir));
    emit shot(bullet);
}

