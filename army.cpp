#include "army.h"
#include "maphelper.h"

void Army::add(Unit unit)
{
    auto key = unit.getName();
    getOrSet(soldierIds, key,0);
    soldierIds[key] = soldierIds[key]+1;



}

void Army::remove(Unit unit)
{
    auto key = unit.getName();
    if(getOrSet(soldierIds, key,0) > 0)
    {
        soldierIds[key] = soldierIds[key]-1;
    }

}

int Army::count(Unit unit)
{
    auto key = unit.getName();
    int result = getOrSet(soldierIds,key,0);
    printf("%s %d\n",key.c_str(), result);
    return result;
}

Army::Army()
{
    soldierIds.clear();
}

