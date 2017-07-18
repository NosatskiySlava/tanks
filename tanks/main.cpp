#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <qqml.h>

#include <Model/tank.h>
#include <Model/tanksfield.h>

#include <gameproperties.h>
#include <gamemanager.h>
#include <inputmanager.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    GameProperties props;
    TanksField tanksField;
    InputManager inputManager;

    QObject::connect(&inputManager, &InputManager::leftPressed, tanksField.player1().get(), &Tank::moveLeft);
    QObject::connect(&inputManager, &InputManager::rightPressed, tanksField.player1().get(), &Tank::moveRight);
    QObject::connect(&inputManager, &InputManager::upPressed, tanksField.player1().get(), &Tank::moveUp);
    QObject::connect(&inputManager, &InputManager::downPressed, tanksField.player1().get(), &Tank::moveDown);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Props", &props);
    engine.rootContext()->setContextProperty("Input", &inputManager);
    engine.rootContext()->setContextProperty("TankPlayer1", tanksField.player1().get());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    GameManager gameManager;
    return app.exec();
}

