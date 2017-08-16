#include "enemytank.h"

#include "Common/gameproperties.h"
#include "Common/position.h"

#include <QDateTime>
#include <QMetaEnum>
#include <QtGlobal>

namespace {
    Position getDeltaMovement(Common::EDirection::Type direction) {
        switch(direction) {
        case Common::EDirection::DOWN:
            return Position(0, 1);
        case Common::EDirection::UP:
            return Position(0, -1);
        case Common::EDirection::LEFT:
            return Position(-1, 0);
        case Common::EDirection::RIGHT:
            return Position(1, 0);
        default:
            Q_ASSERT_X(FALSE, "enemytank.getdeltamovement", "non valid direction was passed");
            return Position(0, 0);
        }
    }

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
