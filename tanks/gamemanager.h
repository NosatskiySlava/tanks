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

class GameManager : public QObject
{
    Q_OBJECT

public:
    static std::shared_ptr<GameManager> instance();
    void exposeObjects(QQmlApplicationEngine& engine);

private:
    explicit GameManager(QObject *parent = 0);
    GameManager(GameManager&);
    GameManager& operator=(GameManager&);

    void update();
    virtual void customEvent(QEvent *);

private:
    std::shared_ptr<TanksField>     m_tanksField;
    std::shared_ptr<InputManager>   m_inputManager;
    std::shared_ptr<GameProperties> m_props;
};

class UpdateEvent: public QEvent {
public:
    UpdateEvent();
};

#endif // GAMEMANAGER_H
