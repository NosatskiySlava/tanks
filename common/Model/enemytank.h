#ifndef ENEMYTANKBEHAVIOR
#define ENEMYTANKBEHAVIOR

#include "Common/common.h"
#include "Common/position.h"

#include <QObject>

class EnemyTank : public QObject {
    Q_OBJECT
public:
    void makeRandomMove(const Position& currentPosition, const Common::EDirection::Type& currentDirection);
    void makeRandomShot();

signals:
    void directionChanged(Common::EDirection::Type dir);
    void positionChanged(const Position& pos);
    void shotMade();

private:
    void makeRandomMove();
    void updatePosition();
    void updateDirection();

private:
    Position tankPosition;
    Common::EDirection::Type tankDirection;
};

#endif // ENEMYTANKBEHAVIOR

