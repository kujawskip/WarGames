#ifndef UNIT_H
#define UNIT_H
class Unit {
std::string name;
int endurance;
int range;
int damage;
int movement;
public:
std::string getName();
int getEndurance();
int getRange();
int getDamage();
int getMovement();
void setName(std::string name);
void setEndurance(int value);
void setRange(int value);
void setDamage(int value);
void setMovement(int movement);
};
#endif // UNIT_H
