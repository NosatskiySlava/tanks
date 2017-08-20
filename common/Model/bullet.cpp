#include "bullet.h"

#include <Common/gameproperties.h>

#include <QtGlobal>

Bullet::Bullet(QObject *parent) : PositionableObject(parent) {

}

Bullet::Bullet(const Position& i_pos, Common::EDirection::Type dir, QObject *parent)
    : PositionableObject(i_pos, dir, parent)
{
}

