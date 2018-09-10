#include "unitprovider.h"
void UnitProvider::load(QJsonObject object)
{

    std::vector<Unit> units;

    this->loadedUnits.clear();
    tryReadArray(units, object, "units");

    for(auto& unit : units)
    {
        this->loadedUnits.insert(this->loadedUnits.end(), std::pair<std::string,Unit>(unit.getName(),unit));
    }

}

Unit UnitProvider::getUnit(std::string key)
{
    return loadedUnits[key];
}

std::vector<Unit> UnitProvider::getUnits()
{
    std::vector<Unit> result;
    for(auto& unit : loadedUnits)
    {
        result.push_back(unit.second);
    }
    return result;
}
