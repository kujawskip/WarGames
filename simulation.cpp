#include "simulation.h"
#include <cstdlib>
int Simulation::getCount()
{
    return snapshots.size();
}

SimulationSnapshot Simulation::getSnapshot(int index)
{
    return snapshots[index];
}

Simulation::Simulation(SimulationData &data)
{
    auto hash = std::hash<std::string>{}(data.getParameters().getSeed());

    std::srand(hash);
    SimulationSnapshot snapshot(data);
    snapshots.push_back(snapshot);
    while(!snapshot.getIsFinished())
    {
        snapshot = snapshot.getNextStep();
        snapshots.push_back(snapshot);
    }
}

Simulation::Simulation()
{

}


