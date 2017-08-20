#ifndef POSITIONABLEOBJECT_H
#define POSITIONABLEOBJECT_H

#include "Common/common.h"
#include "Common/position.h"

#include <QObject>

class PositionableObject : public QObject {
    Q_OBJECT

    Q_PROPERTY(int x READ x NOTIFY xChanged)
    Q_PROPERTY(int y READ y NOTIFY yChanged)

public:
    int x() const;
    int y() const;
    Common::EDirection::Type dir() const;

    virtual void move();

signals:
    void xChanged();
    void yChanged();
    void dirChanged();


protected:
    PositionableObject(QObject* parent = nullptr);
    PositionableObject(const Position& pos, Common::EDirection::Type dir, QObject* parent = nullptr);

    void setX(int x);
    void setY(int y);
    void setDirection(Common::EDirection::Type direction);

    Position getPosition() const;
    void setPosition(const Position& pos);

    void moveObjectTowardsDirection();
    Position getDeltaMovement(Common::EDirection::Type direction) const;

private:
    Position position;
    Common::EDirection::Type m_dir;
};

#endif //POSITIONABLEOBJECT_H
