#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QEvent>
#include <QObject>

#include <memory>
#include <list>

class GameProperties;
class InputManager;
class TanksField;

class QQmlApplicationEngine;

class GameWorld : public QObject
{
    Q_OBJECT

public:
    static std::shared_ptr<GameWorld> instance();
    void exposeObjectsToQml(QQmlApplicationEngine& engine);

private:
    explicit GameWorld(QObject *parent = 0);
    GameWorld(GameWorld&);
    GameWorld& operator=(GameWorld&);

    void update();
    virtual void customEvent(QEvent *);

private:
    std::shared_ptr<TanksField>     m_tanksField;
    std::shared_ptr<InputManager>   m_inputManager;
    std::shared_ptr<GameProperties> m_props;
};

#endif // GAMEMANAGER_H
