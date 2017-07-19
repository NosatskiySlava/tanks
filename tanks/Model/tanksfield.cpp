#include "tanksfield.h"

#include "bullet.h"
#include "tank.h"

TanksField::TanksField()
  : m_player1(new Tank())
{
    connect(m_player1.get(), &Tank::shot, this, &TanksField::addBullet);
}

const std::shared_ptr<Tank> TanksField::player1() const {
    return m_player1;
}

void TanksField::addBullet(const std::shared_ptr<Bullet>& i_bullet) {
    m_bullets.push_back(i_bullet);
    emit bulletAdded();
}



