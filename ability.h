#ifndef ABILITY_H
#define ABILITY_H
#include "jsonwrapper.h"
#include "attack.h"

class SimulatedUnit;

class Ability {

public:
    void virtual Affect(Attack& attack, SimulatedUnit& owner)
    {

    }
    int quantity;
};

class ArmorReduction : public Ability {
public:
    void Affect(Attack& attack, SimulatedUnit& owner);
};

class AccuracyBoost : public Ability {
    void Affect(Attack& attack, SimulatedUnit& owner);
};

template<>
void asInstanceOf<Ability>(Ability& value, QJsonValue object);

#endif // ABILITY_H
