#include "tanksfield.h"

#include "tank.h"

TanksField::TanksField(QObject *parent) : QObject(parent)
  , m_player1(nullptr)
{

}

int TanksField::fieldWidth() const {
    return m_fieldWidth;
}

int TanksField::fieldHeight() const {
    return m_fieldHeight;
}

void TanksField::setPlayer1(QObject* tank) {
    m_player1 = dynamic_cast<Tank*>(tank);
}

QObject* TanksField::player1() const {
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
