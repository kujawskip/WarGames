#include "ability.h"
#include "simulatedunit.h"
template<>
void asInstanceOf<Ability>(Ability& value, QJsonValue object)
{
    auto jsonObject = object.toObject();
    if(jsonObject.contains("type") && jsonObject.contains("value") && jsonObject["value"].isDouble())
    {
        int quantity = 0;
        asInstanceOf<int>(quantity, jsonObject["value"]);
        if(jsonObject["type"].toString() == "armor")
        {
            value = ArmorReduction();
        }
        else
        {
            value = AccuracyBoost();
        }
        value.quantity = quantity;
    }
}

void ArmorReduction::Affect(Attack &attack, SimulatedUnit& owner)
{
    if(attack.getTarget() == owner.getID())
    {
        attack.setDamage((100 - this->quantity)*attack.getDamage()/100);
    }
}

void AccuracyBoost::Affect(Attack &attack, SimulatedUnit& owner)
{
    if(attack.getAttacker() == owner.getID())
    {
        attack.setAccuracy((100 + this->quantity)*attack.getAccuracy()/100);
    }
}
