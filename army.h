#ifndef ARMY_H
#define ARMY_H
#include <vector>
#include <unit.h>
#include "jsonwrapper.h"

class Army
{

    std::vector<std::string> soldierIds;
public:
    void add(Unit unit);
    void remove(Unit unit);
    void read(QJsonObject& object);
};

template<>
void asInstanceOf<Army>(Army& value,QJsonValue object);

#endif // ARMY_H
