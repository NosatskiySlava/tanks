#ifndef TESTSUITS_H
#define TESTSUITS_H

#include <QObject>

#include <vector>

class TestSuits : public QObject
{
    Q_OBJECT
public:
    explicit TestSuits();
    ~TestSuits();

    static std::vector<QObject*>& suits();
};

#endif // TESTSUITS_H
