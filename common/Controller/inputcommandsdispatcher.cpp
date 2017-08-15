#include "inputcommandsdispatcher.h"

InputCommandsDispatcher::InputCommandsDispatcher(QObject *parent) : QObject(parent) {

}

void InputCommandsDispatcher::executeCommand(Qt::Key i_key) {
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
    case Qt::Key_Space:
        emit spacePressed();
    default:
        break;
    }
}


