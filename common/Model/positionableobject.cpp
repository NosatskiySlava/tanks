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

void PositionableObject::setPosition(const Position& pos) {
    position = pos;
}
