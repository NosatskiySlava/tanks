#include "typeregistrator.h"

#include <Controller/gamemanager.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    TypeRegistrator::registerTypes();
    QQmlApplicationEngine engine;

    auto manager = GameManager::instance();
    manager->exposeObjects(engine);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

