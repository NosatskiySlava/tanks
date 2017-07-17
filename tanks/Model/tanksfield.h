#ifndef TANKSFIELD_H
#define TANKSFIELD_H

#include <QObject>

class Tank;

class TanksField : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* player1 READ player1 WRITE setPlayer1 NOTIFY player1Changed)

public:
    explicit TanksField(QObject *parent = 0);

    Q_INVOKABLE void movePlayer1Up();
    Q_INVOKABLE void movePlayer1Down();
    Q_INVOKABLE void movePlayer1Left();
    Q_INVOKABLE void movePlayer1Right();

    void setPlayer1(QObject* player1);
    QObject* player1() const;

signals:
    void player1Changed();

private:
    Tank* m_player1;
};

#endif // TANKSFIELD_H
