#ifndef SIMULATIONSNAPSHOT_H
#define SIMULATIONSNAPSHOT_H
#include "simulatedunit.h"
#include "point.h"
#include "area.h"
#include "simulationdata.h"
class SimulationSnapshot
{
    std::map<int, SimulatedUnit> units;
    std::map<Point, int> positions;
    std::map<Point, int> newPositions;
    Area area;
    bool isFinished;
    int index;
    int accuracy;
    int damage;
    int speed;


public:
    Area getArea();
    bool getIsFinished();
    SimulationSnapshot();
    SimulationSnapshot(SimulationData& data);
    SimulationSnapshot getNextStep();

    std::vector<SimulatedUnit> getPossibleTargets(Point p, int range);
    Point getLocationClosesToEnemyInRange(Point p, int range, int army);
    bool containsUnit(Point p);
    SimulatedUnit getUnit(Point p);
    int getCount(std::string key, int army);
};
#endif // SIMULATIONSNAPSHOT_H
