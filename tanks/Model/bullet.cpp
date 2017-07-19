#include "bullet.h"

#include <QtGlobal>

Bullet::Bullet(Common::EDirection::Type dir, QObject *parent) : QObject(parent)
, m_dir(dir)
{
    Q_ASSERT_X(m_dir == Common::EDirection::NONE, "Initialization of bullet", "Direction is not set");
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
        break;
    }
}

int Bullet::x() const {
    return m_pos.x;
}

int Bullet::y() const {
    return m_pos.y;
}

Common::EDirection::Type Bullet::dir() const
{
    return m_dir;
}

