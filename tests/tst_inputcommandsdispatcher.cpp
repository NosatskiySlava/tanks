#include <gtest/gtest.h>

#include <Controller/inputcommandsdispatcher.h>

namespace  {
    class SignalSpy : public QObject {
        Q_OBJECT

        using QObject::connect;

    public:
        SignalSpy()
            : emited(false)
        {

        }

        void connect(const QObject *sender, const char *signal) {
            QObject::connect(sender, signal, this, SLOT(onEmited()));
        }

        bool isEmited() const {
            return emited;
        }

    private slots:
        void onEmited() {
            emited = true;
        }

    private:
        bool emited;
    };
}

TEST(tst_inputcommandsdispacher, leftButtonPressed) {
    SignalSpy spy;

    InputCommandsDispatcher dispatcher;
    spy.connect(&dispatcher, SIGNAL(leftPressed()));
    dispatcher.executeCommand(Qt::Key_Left);
    ASSERT_TRUE(spy.isEmited());
}

TEST(tst_inputcommandsdispacher, rightButtonPressed) {
    SignalSpy spy;

    InputCommandsDispatcher dispatcher;
    spy.connect(&dispatcher, SIGNAL(rightPressed()));
    dispatcher.executeCommand(Qt::Key_Right);
    ASSERT_TRUE(spy.isEmited());
}

TEST(tst_inputcommandsdispacher, upButtonPressed) {
    SignalSpy spy;

    InputCommandsDispatcher dispatcher;
    spy.connect(&dispatcher, SIGNAL(upPressed()));
    dispatcher.executeCommand(Qt::Key_Up);
    ASSERT_TRUE(spy.isEmited());
}

TEST(tst_inputcommandsdispacher, downButtonPressed) {
    SignalSpy spy;

    InputCommandsDispatcher dispatcher;
    spy.connect(&dispatcher, SIGNAL(downPressed()));
    dispatcher.executeCommand(Qt::Key_Down);
    ASSERT_TRUE(spy.isEmited());
}

TEST(tst_inputcommandsdispacher, spaceButtonPressed) {
    SignalSpy spy;

    InputCommandsDispatcher dispatcher;
    spy.connect(&dispatcher, SIGNAL(spacePressed()));
    dispatcher.executeCommand(Qt::Key_Space);
    ASSERT_TRUE(spy.isEmited());
}

#include <tst_inputcommandsdispatcher.moc>
