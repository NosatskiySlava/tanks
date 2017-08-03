#include "gameproperties.h"

GameProperties::GameProperties(QObject *parent) : QObject(parent) {

}

int GameProperties::fieldWidth() {
    return m_fieldWidth;
}

int GameProperties::fieldHeight() {
    return m_fieldHeight;
}

int GameProperties::bulletIconHeight() {
    return m_bulletIconHeight;
}

int GameProperties::bulletIconWidth() {
    return m_bulletIconWidth;
}

int GameProperties::tankImageSize() {
    return m_tankImageSize;
}

int GameProperties::tankIconSize() {
    return m_tankIconSize;
}

int GameProperties::bulletImageHeight() {
    return m_bulletImageHeight;
}

int GameProperties::bulletImageWidth() {
    return m_bulletImageWidth;
}

