TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    position.cpp \
    Model/tank.cpp \
    Model/tanksfield.cpp \
    gameproperties.cpp \
    gamemanager.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Model/tank.h \
    postion.h \
    Model/tanksfield.h \
    gameproperties.h \
    gamemanager.h

