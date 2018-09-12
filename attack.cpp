#include "attack.h"
int Attack::getAccuracy()
{
    return accuracy;
}

int Attack::getTarget()
{
    return target;
}

int Attack::getDamage()
{
    return damage;
}

int Attack::getAttacker()
{
    return attacker;
}

void Attack::setAccuracy(int value)
{
    accuracy = value;
}

void Attack::setDamage(int value)
{
    damage = value;
}

void Attack::setAttacker(int attacker)
{
    this->attacker = attacker;
}


void Attack::setTarget(int value)
{
    this->target = value;
}
