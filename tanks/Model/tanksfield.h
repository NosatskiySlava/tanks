#ifndef TANKSFIELD_H
#define TANKSFIELD_H

#include <QObject>

#include <memory>

class Tank;

class TanksField : public QObject
{
    Q_OBJECT

public:
    explicit TanksField(QObject *parent = 0);

    Q_INVOKABLE void movePlayer1Up();
    Q_INVOKABLE void movePlayer1Down();
    Q_INVOKABLE void movePlayer1Left();
    Q_INVOKABLE void movePlayer1Right();

    const std::shared_ptr<Tank> player1() const;

private:
    std::shared_ptr<Tank> m_player1;
};

#endif // TANKSFIELD_H
