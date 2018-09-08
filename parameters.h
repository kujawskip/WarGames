#pragma once
#include <string>
#include "jsonwrapper.h"
#define ACCURACY_VALUES_COUNT 10
#define DAMAGE_VALUES_COUNT 10
#define SPEED_VALUES_COUNT 10
static int accuracyValues[ACCURACY_VALUES_COUNT] = {10,20,30,40,50,60,70,80,90,100};
static int damageValues[DAMAGE_VALUES_COUNT] = {50,60,70,80,90,100,110,120,130,140};
static int speedValues[SPEED_VALUES_COUNT] = {50,60,70,80,90,100,110,120,130,140};
class SimulationParameters {
    int accuracy;
    int damage;
    int speed;
    std::string seed;
   public:
    int getAccuracy();
    int getDamage();
    int getSpeed();
    std::string getSeed();
    void setAccuracy(int value);
    void setDamage(int value);
    void setSpeed(int value);
    void setSeed(std::string value);
    SimulationParameters();
    void read(QJsonObject& object);
};

template<>
void asInstanceOf<SimulationParameters>(SimulationParameters& value,QJsonValue object);
