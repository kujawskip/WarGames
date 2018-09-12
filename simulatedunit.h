#ifndef SIMULATEDUNIT_H
#define SIMULATEDUNIT_H
#include "attack.h"
#include "unit.h"
class SimulatedUnit {

    int HP;
    int Id;
    int Army;
    Unit BaseUnit;
public:
    Unit getUnit();
    int getHP();
    int getID();
    int getArmy();
    SimulatedUnit getCopy();
    void apply(Attack& attack);
    SimulatedUnit();
    SimulatedUnit(Unit BaseUnit,int id,int army);
    void multiplyHP(int multiplier);


};
#endif // SIMULATEDUNIT_H
