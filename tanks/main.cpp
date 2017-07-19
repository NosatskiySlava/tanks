#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <gamemanager.h>
#include <common.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Common::RegisterCommonTypes();
    QQmlApplicationEngine engine;

    auto manager = GameManager::instance();
    manager->exposeObjects(engine);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

