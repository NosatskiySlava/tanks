#include "gamemanager.h"
#include "inputmanager.h"

#include <Common/gameproperties.h>
#include <Model/tank.h>
#include <Model/tanksfield.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

std::shared_ptr<GameManager> GameManager::instance() {
    static std::shared_ptr<GameManager> manager(nullptr);
    if (manager == nullptr) {
        manager = std::shared_ptr<GameManager>(new GameManager());
    }
    return manager;
}

void GameManager::exposeObjects(QQmlApplicationEngine& engine)
{
    engine.rootContext()->setContextProperty("Props", m_props.get());
    engine.rootContext()->setContextProperty("Input", m_inputManager.get());
    engine.rootContext()->setContextProperty("TanksField", m_tanksField.get());
    engine.rootContext()->setContextProperty("TankPlayer1", m_tanksField->player1().get());
}

GameManager::GameManager(QObject *parent)
    : QObject(parent)
    , m_tanksField(new TanksField())
    , m_inputManager(new InputManager())
    , m_props(new GameProperties())
{
    QObject::connect(m_inputManager.get(), &InputManager::leftPressed, m_tanksField->player1().get(), &Tank::moveLeft);
    QObject::connect(m_inputManager.get(), &InputManager::rightPressed, m_tanksField->player1().get(), &Tank::moveRight);
    QObject::connect(m_inputManager.get(), &InputManager::upPressed, m_tanksField->player1().get(), &Tank::moveUp);
    QObject::connect(m_inputManager.get(), &InputManager::downPressed, m_tanksField->player1().get(), &Tank::moveDown);
    QObject::connect(m_inputManager.get(), &InputManager::spacePressed, m_tanksField->player1().get(), &Tank::makeShot);

    QGuiApplication::instance()->postEvent(this, new UpdateEvent());
}

void GameManager::update() {
    m_tanksField->update();
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

