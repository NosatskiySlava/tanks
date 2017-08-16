#ifndef TANK_H
#define TANK_H

#include "positionableobject.h"

#include <Common/position.h>
#include <Common/common.h>

#include <memory>

class Bullet;

class Tank: public PositionableObject {
Q_OBJECT

public:
    explicit Tank(QObject* parent = nullptr);
    Tank(const Position& i_pos, Common::EDirection::Type i_dir = Common::EDirection::UP, QObject* parent = nullptr);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void makeShot();

signals:
    void movedLeft();
    void movedRight();
    void movedUp();
    void movedDown();
    void shot(std::shared_ptr<Bullet>);

private:
    Common::EDirection::Type m_dir;
};

#endif // TANK_H

