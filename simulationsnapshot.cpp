#include "simulationsnapshot.h"
#include "unitprovider.h"
bool SimulationSnapshot::containsUnit(Point p)
{
    return (this->positions.find(p) != this->positions.end());
}

Area SimulationSnapshot::getArea()
{
    return area;
}

SimulatedUnit SimulationSnapshot::getUnit(Point p)
{
    return this->units[this->positions[p]];
}

SimulationSnapshot::SimulationSnapshot()
{

}

SimulationSnapshot SimulationSnapshot::getNextStep()
{
    for(auto& units : positions)
    {
        auto point = units.first;
        auto unit = this->units[units.second];
        auto newPoint = this->getLocationClosesToEnemyInRange(point,unit.getUnit().getMovement()*this->speed/100, unit.getArmy());
        newPositions[newPoint] = unit.getID();
    }
    std::map<int, SimulatedUnit> fightingUnits;
    for(auto& units : units)
    {
        int key = units.first;
        fightingUnits.insert(std::pair<int,SimulatedUnit>(key,units.second.getCopy()));
    }

    for(auto& units: newPositions)
    {
        auto point = units.first;
        auto unit = this->units[units.second];
        auto possibleAttacks = this->getPossibleTargets(point,unit.getUnit().getRange());
        int target = -1;
        for(auto& attack : possibleAttacks)
        {


            if(attack.getHP()>0 && attack.getArmy()!=unit.getArmy())
            {
                target = attack.getID();
                break;
            }

        }
        if(target > 0)
        {
            Attack attack;
            attack.setAttacker(unit.getID());
            attack.setTarget(target);
            attack.setDamage(unit.getUnit().getDamage()*this->damage/100);
            attack.setAccuracy(this->accuracy);
            for(auto& ability : unit.getUnit().getAbilities())
            {
                ability.Affect(attack, unit);
            }
            fightingUnits[target].apply(attack);

        }


    }
    SimulationSnapshot result;
    result.index = index+1;
    result.accuracy = accuracy;
    int armies[]= {0,0};
    for(auto& position : newPositions)
    {
        auto pos = position.first;
        auto unit = fightingUnits[position.second];
        if(unit.getHP() > 0)
        {
            result.positions.insert(position);
            result.units.insert(std::pair<int,SimulatedUnit>(unit.getID(),unit));
            armies[unit.getArmy()]++;
        }
    }
    result.speed = this->speed;
    result.damage = this->damage;
    result.isFinished = armies[0]*armies[1] == 0 || result.index == 100;
    return result;
}

bool SimulationSnapshot::getIsFinished()
{
    return isFinished;
}

SimulationSnapshot::SimulationSnapshot(SimulationData &data)
{
    this->speed = data.getParameters().getSpeed();
    this->damage = data.getParameters().getDamage();
    this->accuracy = data.getParameters().getAccuracy();
    this->area = data.getArea();
    int id = 0;
    this->isFinished = false;
    for(auto& soldier : UnitProvider::getInstance().getUnits())
    {
        auto redList = data.getPlacement().getPositions(soldier.getName(),true);
        auto blueList = data.getPlacement().getPositions(soldier.getName(),false);
        for(auto& point : redList)
        {
            SimulatedUnit simUnit(soldier,id,0);
            id++;
            this->positions.insert(std::pair<Point, int>(point,simUnit.getID()));
            this->units.insert(std::pair<int,SimulatedUnit>(simUnit.getID(),simUnit));
        }
        for(auto& point : blueList)
        {
            SimulatedUnit simUnit(soldier,id,1);
            id++;
            this->positions.insert(std::pair<Point, int>(point,simUnit.getID()));
            this->units.insert(std::pair<int,SimulatedUnit>(simUnit.getID(),simUnit));
        }
    }
}

int SimulationSnapshot::getCount(std::string key, int value)
{
    int count = 0;
    for(auto& item : units)
    {
        if(item.second.getUnit().getName() == key && item.second.getArmy() == value) count++;
    }
    return count;
}
Point SimulationSnapshot::getLocationClosesToEnemyInRange(Point p, int range, int army)
{
    int seeking = 1 - army;
    Point seekingPoint = p;
    Point current = p;
    for(auto& pos : positions)
    {
        auto unit = units[pos.second];
        if(unit.getArmy() == seeking)
        {
            seekingPoint = pos.first;
        }
    }
    for(int i = 0; i < range; i ++)
    {
        Point tryPoint;
        int dx = (seekingPoint.getX()>=current.getX())?1:-1;
        int dy = (seekingPoint.getY()>=current.getY())?1:-1;
        int diffX = dx*(seekingPoint.getX()-current.getX());
        int diffY = dy*(seekingPoint.getY()-current.getY());
        if(diffX>diffY)
        {
            tryPoint.setX(current.getX() + dx);
            tryPoint.setY(current.getY());
        }
        else
        {
            tryPoint.setX(current.getX());
            tryPoint.setY(current.getY()+dy);
        }
        if(area.isTilePassable(tryPoint) && positions.find(tryPoint) == positions.end() && newPositions.find(tryPoint) == newPositions.end())
        {
            current = tryPoint;
            continue;
        }


    }
    return current;
}

std::vector<SimulatedUnit> SimulationSnapshot::getPossibleTargets(Point p, int range)
{
    std::vector<SimulatedUnit> result;
    for(auto& location : positions)
    {
        auto pos = location.first;
        if( (p.getX() - pos.getX())*(p.getX() - pos.getX()) + (p.getY() - pos.getY())*(p.getY() - pos.getY()) < range*range )
        {
            auto unit = units[location.second];
            result.push_back(unit);
        }


    }
    return result;
}
