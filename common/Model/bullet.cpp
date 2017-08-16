#include "bullet.h"

#include <Common/gameproperties.h>

#include <QtGlobal>

Bullet::Bullet(QObject *parent) : QObject(parent) {

}

Bullet::Bullet(const Position& i_pos, Common::EDirection::Type dir, QObject *parent) : QObject(parent)
, m_dir(dir)
, m_pos(i_pos)
{
}

void Bullet::move() {
    switch (m_dir) {
    case Common::EDirection::LEFT:
        --m_pos.x;
        emit xChanged();
        break;
    case Common::EDirection::RIGHT:
        ++m_pos.x;
        emit xChanged();
        break;
    case Common::EDirection::DOWN:
        ++m_pos.y;
        emit yChanged();
        break;
    case Common::EDirection::UP:
        --m_pos.y;
        emit yChanged();
        break;
    default:
        Q_ASSERT_X(false, "movement of bullet", "Direction is not set");
        break;
    }
}

int Bullet::x() const {
    return m_pos.x;
}

int Bullet::y() const {
    return m_pos.y;
}

Common::EDirection::Type Bullet::dir() const {
    return m_dir;
}

Bullet::~Bullet() {
}

