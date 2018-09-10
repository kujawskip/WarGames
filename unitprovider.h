#ifndef UNITPROVIDER_H
#define UNITPROVIDER_H
#include <map>
#include <vector>
#include "unit.h"


class UnitProvider
{
    public:
        static UnitProvider& getInstance()
        {
            static UnitProvider    instance;

            return instance;
        }
    private:

        std::map<std::string,Unit> loadedUnits;

        UnitProvider()
        {

        }
    public:
        UnitProvider(UnitProvider const&)               = delete;
        void operator=(UnitProvider const&)  = delete;
        void load(QJsonObject object);
        Unit getUnit(std::string key);
        std::vector<Unit> getUnits();
};
#endif // UNITPROVIDER_H
