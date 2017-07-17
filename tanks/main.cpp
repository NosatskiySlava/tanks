#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <qqml.h>

#include <Model/tank.h>
#include <Model/tanksfield.h>

#include<gameproperties.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    GameProperties props;
    TanksField tanksField;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Props", &props);
    engine.rootContext()->setContextProperty("TankPlayer1", tanksField.player1().get());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

