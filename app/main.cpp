#include "gameworld.h"
#include "typeregistrator.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    TypeRegistrator::registerTypes();
    QQmlApplicationEngine engine;

    auto world = GameWorld::instance();
    world->exposeObjectsToQml(engine);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

