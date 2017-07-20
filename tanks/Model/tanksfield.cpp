#include "tanksfield.h"

#include "bullet.h"
#include "tank.h"

#include <gameproperties.h>

#include <qqml.h>

namespace  {
    bool isHit(std::shared_ptr<Bullet> i_bullet) {
        Position pos(i_bullet->x(), i_bullet->y());
        if (!(pos.x > 0 && pos.y > 0 &&
             pos.x < GameProperties::fieldWidth() - GameProperties::bulletIconHeight() &&
             pos.y < GameProperties::fieldHeight() - GameProperties::bulletIconHeight())) {
            return true;
        }

        return false;
    }
}


TanksField::TanksField()
  : m_player1(new Tank())
{
    connect(m_player1.get(), &Tank::shot, this, &TanksField::addBullet);
    qmlRegisterType<Bullet>("model.bullet", 1, 0, "huy");
}

const std::shared_ptr<Tank> TanksField::player1() const {
    return m_player1;
}

void TanksField::addBullet(const std::shared_ptr<Bullet>& i_bullet) {
    m_bullets.push_back(i_bullet);
    emit bulletAdded(i_bullet.get());
}

void TanksField::update() {
    for (auto bullet: m_bullets) {
        bullet->move();
    }
    for (auto itr = m_bullets.begin(); itr != m_bullets.end(); ++itr) {
        auto bullet = *itr;
        if (isHit(bullet)) {
            emit bullet->hit();
            itr = ++itr;
            m_bullets.remove(bullet);
        }
    }
}



