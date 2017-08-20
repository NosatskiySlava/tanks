#ifndef BULLET_H
#define BULLET_H

#include <Common/common.h>
#include <Common/position.h>

#include "positionableobject.h"

class Bullet : public PositionableObject {
    Q_OBJECT

    Q_PROPERTY(Common::EDirection::Type dir READ dir CONSTANT)

public:
    explicit Bullet(QObject *parent = 0);
    Bullet(const Position& i_pos, Common::EDirection::Type dir, QObject *parent = 0);

signals:
    void hit();
};

#endif // BULLET_H
