#include "typeregistrator.h"

#include <Common/common.h>
#include <Model/bullet.h>

#include <qqml.h>

void TypeRegistrator::registerTypes() {
    qmlRegisterType<Common::EDirection>("CommonTypes", 1, 0, "Direction");
    qmlRegisterType<Bullet>("model.bullet", 1, 0, "ballet");
}
