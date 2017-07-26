#-------------------------------------------------
#
# Project created by QtCreator 2017-07-21T17:56:56
#
#-------------------------------------------------

QT += qml quick

TARGET = common
TEMPLATE = lib
CONFIG += c++11 staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -lgcov
QMAKE_CXXFLAGS += -g -Wall -fprofile-arcs -ftest-coverage -O0

SOURCES += \
    Common/gameproperties.cpp \
    Common/position.cpp \
    Controller/gamemanager.cpp \
    Controller/inputmanager.cpp \
    Model/bullet.cpp \
    Model/tank.cpp \
    Model/tanksfield.cpp

HEADERS += \
    Common/common.h \
    Common/gameproperties.h \
    Common/postion.h \
    Controller/gamemanager.h \
    Controller/inputmanager.h \
    Model/bullet.h \
    Model/tank.h \
    Model/tanksfield.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
