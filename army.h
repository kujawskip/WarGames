#ifndef ARMY_H
#define ARMY_H
#include <vector>
#include <unit.h>
#include "jsonwrapper.h"
#include <map>
class Army
{
    std::map<std::string, int > soldierIds;

public:

    void add(Unit unit);
    void remove(Unit unit);
    void read(QJsonObject& object);
    int count(Unit unit);
    Army();
};

template<>
void asInstanceOf<Army>(Army& value,QJsonValue object);

#endif // ARMY_H
