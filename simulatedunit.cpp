#include "simulatedunit.h"
#include <cstdlib>
#include "unit.h"
void SimulatedUnit::apply(Attack &attack)
{
    for(auto& ability : this->BaseUnit.getAbilities())
    {
        ability.Affect(attack,*this);
    }


    if(std::rand()%100 <= attack.getAccuracy())
    {
        this->HP = this->HP - attack.getDamage();
    }

}

SimulatedUnit SimulatedUnit::getCopy()
{
    auto unit = SimulatedUnit(BaseUnit,Id,Army);
    unit.HP = HP;
    return unit;
}

SimulatedUnit::SimulatedUnit(Unit BaseUnit, int id, int army)
{
    this->BaseUnit = BaseUnit;
    this->HP = this->BaseUnit.getEndurance();
    this->Id = id;
    this->Army = army;

}

int SimulatedUnit::getArmy()
{
    return Army;
}

int SimulatedUnit::getHP()
{
    return HP;
}

int SimulatedUnit::getID()
{
    return Id;
}

Unit SimulatedUnit::getUnit()
{
    return BaseUnit;
}

SimulatedUnit::SimulatedUnit()
{

}

void SimulatedUnit::multiplyHP(int multiplier)
{
    HP = HP*multiplier/100;
}

