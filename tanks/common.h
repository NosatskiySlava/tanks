#ifndef COMMON_H
#define COMMON_H

#include <QObject>
#include <qqml.h>

namespace Common {
    class EDirection: public QObject {

        Q_OBJECT

    public:
        enum Type {
            NONE,
            UP,
            LEFT,
            RIGHT,
            DOWN
        };
        Q_ENUMS(Type)
    };

    void RegisterCommonTypes();
}

#endif // COMMON_H
