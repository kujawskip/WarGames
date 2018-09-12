#ifndef SIMULATIONDATA_H
#define SIMULATIONDATA_H
#include "area.h"
#include "army.h"
#include "placement.h"
#include "parameters.h"
class SimulationData {
    Area area;
    Army redArmy;
    Army blueArmy;
    Placement placement;
    SimulationParameters parameters;
public:

    Area& getArea();
    Army& getRedArmy();
    Army& getBlueArmy();
    Placement& getPlacement();
    SimulationParameters& getParameters();

};
#endif // SIMULATIONDATA_H
