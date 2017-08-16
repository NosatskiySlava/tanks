#include "positionableobject.h"

PositionableObject::PositionableObject(QObject *parent)
    : QObject(parent)
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

void PositionableObject::setPosition(const Position& pos) {
    setX(pos.x);
    setY(pos.y);
}
