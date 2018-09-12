#ifndef PLACEMENTGROUP_H
#define PLACEMENTGROUP_H
#include <QtWidgets>
#include "army.h"
#include "placement.h"
#include "placementgrouplabel.h"
#include "groupunitlabel.h"
class PlacementGroup : public QWidget
{
private:
    Q_OBJECT
    Army& army;
    Placement& placement;
    QHBoxLayout* layout;
    QMap<std::string, PlacementGroupLabel*> labels;
    std::function<void(std::string)> onSelected;
    std::string selectedUnit;
    bool isRedArmy;
public:
    PlacementGroup(QWidget *parent, Army& army,Placement& placement, std::function<void(std::string)> onSelected, QString name);
    void armyUpdated();
    std::string getSelectedUnit();
    void unitAdded(std::string unit);
    void unitRemoved(std::string unit);
    void placementUpdated();
};

#endif // PLACEMENTGROUP_H
