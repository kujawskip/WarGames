#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H
#include <QtWidgets>
#include "simulation.h"
#include "simulatedunitdetails.h"
#include "simulationunitgroup.h"
#include "simulationrenderer.h"
class SimulationWindow : public QMainWindow
{
    Q_OBJECT
    Simulation simulation;
    SimulationRenderer* renderer;
    QSlider* iterationSlider;
    SimulatedUnitDetails* details;
    SimulationUnitGroup* redGroup;
    SimulationUnitGroup* blueGroup;
public:
    SimulationWindow(SimulationData& data);
    void setSnapshot(int snapshotId);
    void pointClicked(Point p);
};
#endif // SIMULATIONWINDOW_H
