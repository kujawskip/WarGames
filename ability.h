#ifndef ABILITY_H
#define ABILITY_H
#include "jsonwrapper.h"
class Ability {


};

class ArmorReduction : public Ability {

};

class AccuracyBoost : public Ability {

};

template<>
void asInstanceOf<Ability>(Ability& value, QJsonValue object);

#endif // ABILITY_H
