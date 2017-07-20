#ifndef TANKSFIELD_H
#define TANKSFIELD_H

#include <QObject>

#include <memory>
#include <list>

class Bullet;
class Tank;

class TanksField : public QObject
{
    Q_OBJECT

public:
    explicit TanksField();

    const std::shared_ptr<Tank> player1() const;

    void addBullet(const std::shared_ptr<Bullet>&);
    void update();

signals:
    void bulletAdded(Bullet* bullet);

private:
    std::shared_ptr<Tank> m_player1;
    std::list<std::shared_ptr<Bullet>> m_bullets;
};

#endif // TANKSFIELD_H
