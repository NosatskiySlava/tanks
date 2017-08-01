#include "testsuits.h"

#include <QDebug>

TestSuits::TestSuits() : QObject()
{
    suits().push_back(this);
}

TestSuits::~TestSuits() {
    suits().erase(std::remove(suits().begin(), suits().end(), this), suits().end());
}

std::vector<QObject*>& TestSuits::suits() {
    static std::vector<QObject*> suits;
    return suits;
}

