#include "unit.h"

void Unit::read(QJsonObject object)
{
    tryRead(endurance, object, "endurance");
    tryRead(name, object, "name");
    QString filename;
    if(tryRead(filename, object, "icon"))
    {
        filename = ":/images/" + filename;
        icon = QImage(filename);
    }
    tryRead(range,object,"range");
    tryRead(damage,object,"damage");
    tryRead(firerate,object,"firerate");
    tryRead(movement,object,"movement");
    tryReadArray(abilities,object,"abilities");
}

std::string Unit::getName()
{
    return name;
}

template<>
void asInstanceOf<Unit>(Unit& value, QJsonValue object)
{
    value.read(object.toObject());
}

QImage Unit::getIcon()
{
    return icon;
}

int Unit::getDamage()
{
    return damage;
}

int Unit::getFirerate()
{
    return firerate;
}

int Unit::getMovement()
{
    return movement;
}

int Unit::getEndurance()
{
    return endurance;
}

int Unit::getRange()
{
    return range;
}

