#ifndef TANK_H
#define TANK_H

#include <Common/postion.h>
#include <Common/common.h>

#include <QObject>
#include <memory>

class Bullet;

class Tank: public QObject {
Q_OBJECT

    Q_PROPERTY(int x READ x NOTIFY xChanged)
    Q_PROPERTY(int y READ y NOTIFY yChanged)

public:
    explicit Tank(QObject* parent = nullptr);
    Tank(const Position& i_pos, Common::EDirection::Type i_dir = Common::EDirection::UP, QObject* parent = nullptr);

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

