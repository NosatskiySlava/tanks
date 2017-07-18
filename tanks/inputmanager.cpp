#include "inputmanager.h"

InputManager::InputManager(QObject *parent) : QObject(parent) {

}

void InputManager::executeCommand(Qt::Key i_key) {
    switch (i_key) {
    case Qt::Key_Left:
        emit leftPressed();
        break;
    case Qt::Key_Right:
        emit rightPressed();
        break;
    case Qt::Key_Up:
        emit upPressed();
        break;
    case Qt::Key_Down:
        emit downPressed();
        break;
    default:
        break;
    }
}

