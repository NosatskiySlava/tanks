#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <QObject>

class InputCommandsDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit InputCommandsDispatcher(QObject *parent = 0);

    Q_INVOKABLE void executeCommand(Qt::Key i_key);

signals:
    void leftPressed();
    void rightPressed();
    void downPressed();
    void upPressed();
    void spacePressed();
};

#endif // INPUTMANAGER_H
