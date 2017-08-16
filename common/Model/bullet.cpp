#include "bullet.h"

#include <Common/gameproperties.h>

#include <QtGlobal>

Bullet::Bullet(QObject *parent) : PositionableObject(parent) {

}

Bullet::Bullet(const Position& i_pos, Common::EDirection::Type dir, QObject *parent)
    : PositionableObject(i_pos, parent)
    , m_dir(dir)
{
}

void Bullet::move() {
    setPosition(getPosition() + getDeltaMovement(m_dir));
}

Common::EDirection::Type Bullet::dir() const {
    return m_dir;
}

