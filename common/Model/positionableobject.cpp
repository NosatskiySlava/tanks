#include "positionableobject.h"

PositionableObject::PositionableObject(QObject *parent)
    : QObject(parent)
{

}

PositionableObject::PositionableObject(const Position& pos, Common::EDirection::Type dir, QObject* parent)
    : QObject(parent)
    , position(pos)
    , m_dir(dir)
{

}

int PositionableObject::x() const {
    return position.x;
}

int PositionableObject::y() const {
    return position.y;
}

Position PositionableObject::getPosition() const {
    return position;
}

void PositionableObject::setX(int x) {
    if (position.x != x) {
        position.x = x;
        emit xChanged();
    }
}

void PositionableObject::setY(int y) {
    if (position.y != y) {
        position.y = y;
        emit yChanged();
    }
}

void PositionableObject::setDirection(Common::EDirection::Type direction) {
    if (m_dir != direction) {
        m_dir = direction;
        emit dirChanged();
    }
}

void PositionableObject::setPosition(const Position& pos) {
    setX(pos.x);
    setY(pos.y);
}

virtual void PositionableObject::move() {
    moveObjectTowardsDirection();
}

void PositionableObject::moveObjectTowardsDirection() {
    setPosition(position + getDeltaMovement(m_dir));
}

Position PositionableObject::getDeltaMovement(Common::EDirection::Type direction) const {
    switch(direction) {
    case Common::EDirection::DOWN:
        return Position(0, 1);
    case Common::EDirection::UP:
        return Position(0, -1);
    case Common::EDirection::LEFT:
        return Position(-1, 0);
    case Common::EDirection::RIGHT:
        return Position(1, 0);
    default:
        Q_ASSERT_X(FALSE, "positionable.getdeltamovement", "non valid direction was passed");
        return Position(0, 0);
    }
}
