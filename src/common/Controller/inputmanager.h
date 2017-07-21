#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <QObject>

class InputManager : public QObject
{
    Q_OBJECT
public:
    explicit InputManager(QObject *parent = 0);

    Q_INVOKABLE void executeCommand(Qt::Key i_key);

signals:
    void leftPressed();
    void rightPressed();
    void downPressed();
    void upPressed();
    void spacePressed();
};

#endif // INPUTMANAGER_H
