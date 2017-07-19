#include "gamemanager.h"

#include <QDebug>
#include <QGuiApplication>

GameManager::GameManager(QObject *parent) : QObject(parent) {
    QGuiApplication::instance()->postEvent(this, new UpdateEvent());
}

void GameManager::update() {
    qDebug() << "Test";
    QGuiApplication::instance()->postEvent(this, new UpdateEvent());
}

void GameManager::customEvent(QEvent *e) {
    if (dynamic_cast<UpdateEvent*>(e)) {
        update();
    }
}

UpdateEvent::UpdateEvent() :
    QEvent(Type::User) {

}

