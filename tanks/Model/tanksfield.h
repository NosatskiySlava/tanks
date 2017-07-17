#ifndef TANKSFIELD_H
#define TANKSFIELD_H

#include <QObject>

class Tank;

class TanksField : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* player1 READ player1 WRITE setPlayer1 NOTIFY player1Changed)
    Q_PROPERTY(int fieldWidth READ fieldWidth)
    Q_PROPERTY(int fieldHeight READ fieldHeight)

public:
    explicit TanksField(QObject *parent = 0);

    Q_INVOKABLE void movePlayer1Up();
    Q_INVOKABLE void movePlayer1Down();
    Q_INVOKABLE void movePlayer1Left();
    Q_INVOKABLE void movePlayer1Right();

    void setPlayer1(QObject* player1);
    QObject* player1() const;

    int fieldWidth() const;
    int fieldHeight() const;

signals:
    void player1Changed();

private:
    //TODO: add attached property here
    const static int tankIconSize = 16;
    const static int tankImageSize = tankIconSize * 2;
    const static int m_fieldWidth = tankImageSize * 13;
    const static int m_fieldHeight = tankImageSize * 13;

    Tank* m_player1;
};

#endif // TANKSFIELD_H
