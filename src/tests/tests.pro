#-------------------------------------------------
#
# Project created by QtCreator 2017-07-21T18:57:21
#
#-------------------------------------------------

QT       -= gui

TARGET = tests
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += tests.cpp \
    tst_tank.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix: LIBS += -L$$OUT_PWD/../common/ -lcommon

INCLUDEPATH += $$PWD/../common
DEPENDPATH += $$PWD/../common

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/release/libcommon.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/debug/libcommon.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/release/common.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/debug/common.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../common/libcommon.a


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3rdParty/googletest/build/googlemock/release/ -lgmock
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3rdParty/googletest/build/googlemock/debug/ -lgmock
else:unix: LIBS += -L$$PWD/../3rdParty/googletest/build/googlemock/ -lgmock

INCLUDEPATH += $$PWD/../3rdParty/googletest/googlemock/include
DEPENDPATH += $$PWD/../3rdParty/googletest/build/googlemock

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/release/libgmock.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/debug/libgmock.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/release/gmock.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/debug/gmock.lib
else:unix: PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/libgmock.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3rdParty/googletest/build/googlemock/gtest/release/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3rdParty/googletest/build/googlemock/gtest/debug/ -lgtest
else:unix: LIBS += -L$$PWD/../3rdParty/googletest/build/googlemock/gtest/ -lgtest

INCLUDEPATH += $$PWD/../3rdParty/googletest/googletest/include
DEPENDPATH += $$PWD/../3rdParty/googletest/build/googlemock/gtest

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/gtest/release/libgtest.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/gtest/debug/libgtest.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/gtest/release/gtest.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/gtest/debug/gtest.lib
else:unix: PRE_TARGETDEPS += $$PWD/../3rdParty/googletest/build/googlemock/gtest/libgtest.a
