#ifndef ENEMYTANKBEHAVIOR
#define ENEMYTANKBEHAVIOR

#include "positionableobject.h"

#include "Common/common.h"

class EnemyTank : public PositionableObject {
    Q_OBJECT
public:
    EnemyTank(QObject* parent = nullptr);

    void makeRandomMove();
    void makeRandomShot();

signals:
    void directionChanged();
    void positionChanged(const Position& pos);
    void shotMade();

private:
    void updatePosition();
    void updateDirection();
    bool canTankMoveInDirection(Common::EDirection::Type dir);

private:
    Common::EDirection::Type tankDirection;
};

#endif // ENEMYTANKBEHAVIOR

