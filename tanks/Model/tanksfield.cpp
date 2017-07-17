#include "tanksfield.h"

#include "tank.h"

TanksField::TanksField(QObject *parent) : QObject(parent)
  , m_player1(new Tank())
{

}

const std::shared_ptr<Tank> TanksField::player1() const {
    return m_player1;
}

void TanksField::movePlayer1Down() {
    if (!m_player1)
        return;

    m_player1->moveDown();
}

void TanksField::movePlayer1Up() {
    if (!m_player1)
        return;

    m_player1->moveUp();
}

void TanksField::movePlayer1Left() {
    if (!m_player1)
        return;

    m_player1->moveLeft();
}

void TanksField::movePlayer1Right() {
    if (!m_player1)
        return;

    m_player1->moveRight();
}
