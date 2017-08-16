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

    Position getPosition() const;

signals:
    void xChanged();
    void yChanged();

protected:
    PositionableObject(QObject* parent = nullptr);

private:
    Position position;
};

#endif //POSITIONABLEOBJECT_H
