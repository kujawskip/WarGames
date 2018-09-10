#include "simulationdata.h"
Area& SimulationData::getArea() {
return this->area;
}

Army& SimulationData::getRedArmy()
{
    return this->redArmy;
}

Army& SimulationData::getBlueArmy()
{
    return this->blueArmy;
}

Placement& SimulationData::getPlacement() {
return this->placement;
}

SimulationParameters& SimulationData::getParameters()
{
    return this->parameters;
}


