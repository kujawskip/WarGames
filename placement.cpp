#include "placement.h"

void Placement::clearPosition(Point p)
{
    this->positionsOfUnits.erase(p);
}

void Placement::setPosition(Point p, std::pair<std::string, bool> unit)
{
    this->positionsOfUnits[p] = unit;
}

std::pair<std::string,bool> Placement::getUnitKey(Point p)
{
    return this->positionsOfUnits[p];
}

bool Placement::hasUnit(Point p)
{
    return this->positionsOfUnits.find(p) != this->positionsOfUnits.end();
}

int Placement::getCount(std::string key, bool value)
{
    int count = 0;
    for(auto& item : positionsOfUnits)
    {
        if(item.second.first == key && item.second.second == value) count++;
    }
    return count;
}

std::vector<Point> Placement::getPositions(std::string key, bool value)
{
    std::vector<Point> result;
    for(auto& item : positionsOfUnits)
    {
        if(item.second.first == key && item.second.second == value)
        {
            result.push_back(item.first);
        }
    }
    return result;
}
