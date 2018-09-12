#ifndef simulationunitgroup_h
#define simulationunitgroup_h
#include "army.h"
#include "groupunitlabel.h"
#include "simulationsnapshot.h"
#include <QtWidgets>
#include "placementgrouplabel.h"
class SimulationUnitGroup : public QWidget
{
private:
    Q_OBJECT
    int army;
    QHBoxLayout* layout;
    QMap<std::string,PlacementGroupLabel*> labels;
public:
    SimulationUnitGroup(QWidget *parent, SimulationSnapshot snapshot, QString name, int army);
    void setSnapshot(SimulationSnapshot snapshot);
};

#endif // ARMYGROUP_H
