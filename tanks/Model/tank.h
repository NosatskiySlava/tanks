#ifndef TANK_H
#define TANK_H

#include <QObject>

#include <memory>

#include <postion.h>
#include <common.h>

class Bullet;

class Tank: public QObject {
Q_OBJECT

    Q_PROPERTY(int x READ x NOTIFY xChanged)
    Q_PROPERTY(int y READ y NOTIFY yChanged)

public:
    explicit Tank(QObject* parent = nullptr);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void makeShot();

    int x() const;
    int y() const;

signals:
    void xChanged();
    void yChanged();
    void movedLeft();
    void movedRight();
    void movedUp();
    void movedDown();
    void shot(std::shared_ptr<Bullet>);

private:
    Position m_pos;
    Common::EDirection::Type m_dir;
};

#endif // TANK_H

