#include "ability.h"

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
    }
}


