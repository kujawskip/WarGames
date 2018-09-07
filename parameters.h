#pragma once
#include <string>
#define ACCURACY_VALUES_COUNT 10
static int accuracyValues[ACCURACY_VALUES_COUNT] = {10,20,30,40,50,60,70,80,90,100};
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
};
