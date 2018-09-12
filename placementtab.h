#ifndef PLACEMENTTAB_H
#define PLACEMENTTAB_H
#include <QtWidgets>
#include "simulationdata.h"
#include "areaandunitsrenderer.h"
#include "placementgroup.h"
#include "labeledlabel.h"
class PlacementTab : public QWidget
{
    Q_OBJECT
    SimulationData& data;
    AreaAndUnitsRenderer* renderer;
    PlacementGroup* redPlacementGroup;
    PlacementGroup* bluePlacementGroup;
    LabeledLabel* currentSelectedUnit;
    bool isRedArmySelected;
public:
    explicit PlacementTab(QWidget *parent, SimulationData& data);
    void AddUnit(Point p);
    void RemoveUnit(Point p);
    void DataUpdated();
    void onSelected(std::string,std::string);
    PlacementGroup* PlacementTab::getArmySelected();
};
#endif // PLACEMENTTAB_H
