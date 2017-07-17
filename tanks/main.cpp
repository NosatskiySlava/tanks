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

    qmlRegisterType<Tank>("tanks.model.tank", 1, 0, "Tank");
    qmlRegisterType<TanksField>("tanks.model.tanksfield", 1, 0, "TanksField");

    GameProperties props;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Props", &props);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

