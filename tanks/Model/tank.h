#ifndef TANK_H
#define TANK_H

#include <QObject>

#include <postion.h>

class Tank: public QObject {
Q_OBJECT

    Q_PROPERTY(int x READ x NOTIFY xChanged)
    Q_PROPERTY(int y READ y NOTIFY yChanged)

public:
    explicit Tank(QObject* parent = nullptr);
    virtual ~Tank();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    int x() const;
    int y() const;

signals:
    void xChanged();
    void yChanged();

private:
    Position m_pos;
};

#endif // TANK_H

