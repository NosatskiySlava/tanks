#include "gameproperties.h"

GameProperties::GameProperties(QObject *parent) : QObject(parent) {

}

int GameProperties::fieldWidth() const {
    return m_fieldWidth;
}

int GameProperties::fieldHeight() const {
    return m_fieldHeight;
}

int GameProperties::tankImageSize() const {
    return m_tankImageSize;
}

int GameProperties::tankIconSize() const {
    return m_tankIconSize;
}

