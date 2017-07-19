#ifndef BULLET_H
#define BULLET_H

#include <QObject>

#include <common.h>
#include <postion.h>

class Bullet : public QObject {
    Q_OBJECT

    Q_PROPERTY(int x READ x NOTIFY xChanged)
    Q_PROPERTY(int y READ y NOTIFY yChanged)
    Q_PROPERTY(Common::EDirection::Type dir READ dir CONSTANT)

public:
    explicit Bullet(const Position& i_pos, Common::EDirection::Type dir, QObject *parent = 0);

    void move();

    int x() const;
    int y() const;
    Common::EDirection::Type dir() const;

signals:
    void xChanged();
    void yChanged();

private:
    Common::EDirection::Type m_dir;
    Position                 m_pos;
};

#endif // BULLET_H
