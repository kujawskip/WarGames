#include "parameters.h"

void SimulationParameters::setAccuracy(int value)
{
    this->accuracy = value;
}

void SimulationParameters::setDamage (int value)
{
    this->damage = value;
}

void SimulationParameters::setSpeed(int value)
{
    this->speed = value;
}

void SimulationParameters::setSeed(std::string value)
{
    this->seed = std::string(value);
}

SimulationParameters::SimulationParameters()
{
    setAccuracy(0);
    setDamage(0);
    setSpeed(0);
    setSeed("");
}
