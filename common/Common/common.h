#ifndef COMMON_H
#define COMMON_H

#include <QObject>

namespace Common {
    class EDirection: public QObject {

        Q_OBJECT

    public:
        enum Type {
            UP,
            LEFT,
            RIGHT,
            DOWN
        };
        Q_ENUMS(Type)
    };
}

#endif // COMMON_H
