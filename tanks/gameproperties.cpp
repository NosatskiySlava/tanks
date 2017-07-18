#include "gameproperties.h"

GameProperties::GameProperties(QObject *parent) : QObject(parent) {

}

int GameProperties::fieldWidth() {
    return m_fieldWidth;
}

int GameProperties::fieldHeight() {
    return m_fieldHeight;
}

int GameProperties::tankImageSize() {
    return m_tankImageSize;
}

int GameProperties::tankIconSize() {
    return m_tankIconSize;
}

