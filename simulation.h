#ifndef SIMULATION_H
#define SIMULATION_H
#include "simulationdata.h"
#include "simulationsnapshot.h"
class Simulation
{
private:
    std::vector<SimulationSnapshot> snapshots;
public:
    Simulation(SimulationData& data);
    Simulation();
    int getCount();
    SimulationSnapshot getSnapshot(int index);
};
#endif // SIMULATION_H
