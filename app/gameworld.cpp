#include "gameworld.h"

#include <Controller/inputmanager.h>
#include <Common/gameproperties.h>
#include <Model/tank.h>
#include <Model/tanksfield.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

namespace  {
    class UpdateEvent: public QEvent {
        public:
            UpdateEvent() :
                QEvent(Type::User) {

            }
    };
}

std::shared_ptr<GameWorld> GameWorld::instance() {
    static std::shared_ptr<GameWorld> world(nullptr);
    if (world == nullptr) {
        world = std::shared_ptr<GameWorld>(new GameWorld());
    }
    return world;
}

GameWorld::GameWorld(QObject *parent)
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

void GameWorld::update() {
    m_tanksField->update();
    QGuiApplication::instance()->postEvent(this, new UpdateEvent());
}

void GameWorld::customEvent(QEvent *e) {
    if (dynamic_cast<UpdateEvent*>(e)) {
        update();
    }
}

void GameWorld::exposeObjectsToQml(QQmlApplicationEngine& engine)
{
    engine.rootContext()->setContextProperty("Props", m_props.get());
    engine.rootContext()->setContextProperty("Input", m_inputManager.get());
    engine.rootContext()->setContextProperty("TanksField", m_tanksField.get());
    engine.rootContext()->setContextProperty("TankPlayer1", m_tanksField->player1().get());
}


