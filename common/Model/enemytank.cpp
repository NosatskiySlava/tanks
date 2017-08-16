#include "enemytank.h"

#include "Common/gameproperties.h"
#include "Common/position.h"

#include <QDateTime>
#include <QMetaEnum>
#include <QtGlobal>

namespace {
    bool isValidPosition(const Position& pos) {
        return (pos.x > 0 && pos.y > 0
                && pos.x < (GameProperties::fieldWidth() - GameProperties::tankImageSize())
                && pos.y < (GameProperties::fieldHeight() - GameProperties::tankImageSize()));
    }

    int getDirectionsConunt() {
        const QMetaObject metaObject = Common::EDirection::staticMetaObject;
        int enumIndex = metaObject.indexOfEnumerator("Type");
        return metaObject.enumerator(enumIndex).keyCount();
    }

    int generateRandomNumberInRange(int maxRange) {
        QDateTime currentDate;
        qsrand(currentDate.toTime_t());
        return qrand() % maxRange;
    }

    bool isTimeToChangeDirection() {
        return generateRandomNumberInRange(100) <= 20;
    }

    Common::EDirection::Type getRandomDirection() {
        return static_cast<Common::EDirection::Type>(generateRandomNumberInRange(getDirectionsConunt()));
    }
}


EnemyTank::EnemyTank(QObject *parent)
    : PositionableObject(parent)
{

}

void EnemyTank::makeRandomMove()
{
    updateDirection();
    updatePosition();
}

void EnemyTank::updateDirection() {
    Common::EDirection::Type newDirection = tankDirection;
    if (isTimeToChangeDirection()) {
        newDirection = getRandomDirection();
    }
    while (!canTankMoveInDirection(newDirection)) {
        newDirection = getRandomDirection();
    }
    if (newDirection != tankDirection) {
        tankDirection = newDirection;
        emit directionChanged();
    }
}

void EnemyTank::updatePosition() {
    setPosition(getPosition() + getDeltaMovement(tankDirection));
}

bool EnemyTank::canTankMoveInDirection(Common::EDirection::Type dir) {
    return isValidPosition(getPosition() + getDeltaMovement(dir));
}

void EnemyTank::makeRandomShot() {

}
