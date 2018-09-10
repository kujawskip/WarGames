#include "jsonmap.h"
void JsonMap::read(QJsonObject object)
{
    tryRead(name, object, "name");
    if(object.contains("value"))
    {
        value = object["value"];
    }
}

QJsonValue JsonMap::getValue()
{
    return value;
}

std::string JsonMap::getName()
{
    return name;
}

template<>
void asInstanceOf<JsonMap>(JsonMap &value, QJsonValue object)
{
    value.read(object.toObject());
}
