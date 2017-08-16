#include "bullet.h"
#include "tank.h"

#include <Common/gameproperties.h>

#include <memory>

namespace {
    //TODO: get rid of magic numbers in calculation of bullet position
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
    : PositionableObject(p)
    , m_dir(Common::EDirection::UP)
{
}

Tank::Tank(const Position& i_pos, Common::EDirection::Type i_dir, QObject* parent)
    : PositionableObject(i_pos, parent)
    , m_dir(i_dir)
{
}

void Tank::moveUp()
{
    m_dir = Common::EDirection::UP;
    if (getPosition().y != 0) {
        setPosition(getPosition() + getDeltaMovement(m_dir));
    }

    emit movedUp();
}

void Tank::moveDown()
{
    m_dir = Common::EDirection::DOWN;
    if (getPosition().y < GameProperties::fieldHeight() - GameProperties::tankImageSize()) {
        setPosition(getPosition() + getDeltaMovement(m_dir));
    }

    emit movedDown();
}

void Tank::moveLeft()
{
    m_dir = Common::EDirection::LEFT;
    if (getPosition().x != 0) {
        setPosition(getPosition() + getDeltaMovement(m_dir));
    }

    emit movedLeft();
}

void Tank::moveRight()
{
    m_dir = Common::EDirection::RIGHT;
    if (getPosition().x < (GameProperties::fieldWidth() - GameProperties::tankImageSize())) {
        setPosition(getPosition() + getDeltaMovement(m_dir));
    }

    emit movedRight();
}

void Tank::makeShot()
{
    std::shared_ptr<Bullet> bullet(new Bullet(calculateBulletPosition(getPosition(), m_dir), m_dir));
    emit shot(bullet);
}

