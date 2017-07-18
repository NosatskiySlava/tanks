#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QEvent>

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = 0);

private:
    void update();
    virtual void customEvent(QEvent *);
};

class UpdateEvent: public QEvent {
public:
    UpdateEvent();
};

#endif // GAMEMANAGER_H
