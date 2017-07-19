#include <common.h>

void Common::RegisterCommonTypes() {
    qmlRegisterType<EDirection>("CommonTypes", 1, 0, "Direction");
}
