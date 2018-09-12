#ifndef UNIT_H
#define UNIT_H
#include <QJsonObject>
#include <QImage>
#include "ability.h"
#include <vector>
#include "jsonwrapper.h"
class Unit {
std::string name;
QImage icon;
int endurance;
int range;
int damage;
int movement;
int firerate;
std::vector<Ability> abilities;
public:
std::string getName();
int getEndurance();
int getRange();
int getDamage();
int getMovement();
int getFirerate();
std::vector<Ability> getAbilities();
QImage getIcon();
void setName(std::string name);
void setEndurance(int value);
void setRange(int value);
void setDamage(int value);
void setMovement(int movement);
void setFirerate(int value);
void read(QJsonObject object);
};

template<>
void asInstanceOf<Unit>(Unit& value, QJsonValue object);

#endif // UNIT_H
