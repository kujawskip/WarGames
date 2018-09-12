#ifndef PLACEMENTTAB_CPP
#define PLACEMENTTAB_CPP
#include "placementtab.h"
#include "areaandunitsrenderer.h"
#include "placementgroup.h"
#include "unitprovider.h"
#include "labeledlabel.h"
PlacementTab::PlacementTab(QWidget *parent, SimulationData& data)
    : QWidget(parent), data(data)
{

    QHBoxLayout *mainLayout = new QHBoxLayout;

    this->currentSelectedUnit = new LabeledLabel(this);
    this->renderer = new AreaAndUnitsRenderer(this, this->data.getArea(),this->data.getPlacement(), [=](Point p){this->AddUnit(p);}, [=](Point p){this->RemoveUnit(p);});
    this->redPlacementGroup = new PlacementGroup(this, this->data.getRedArmy(), this->data.getPlacement(), [=](std::string key) {
        this->onSelected(key, "Armia pierwsza"); this->isRedArmySelected = true;

    }, "Armia pierwsza");

    this->bluePlacementGroup = new PlacementGroup(this, this->data.getBlueArmy(),this->data.getPlacement(),[=](std::string key) {
        this->onSelected(key, "Armia druga"); this->isRedArmySelected=false;

    }, "Armia druga");
    mainLayout->addStretch(1);
    mainLayout->addWidget(this->renderer);
    QVBoxLayout* groupLayout = new QVBoxLayout;
    groupLayout->addWidget(this->redPlacementGroup);
    groupLayout->addWidget(this->bluePlacementGroup);
    groupLayout->addWidget(this->currentSelectedUnit);
    mainLayout->addLayout(groupLayout);
    setLayout(mainLayout);

}

PlacementGroup* PlacementTab::getArmySelected()
{
    if(this->isRedArmySelected)
    {
        return redPlacementGroup;
    }
    else
    {
        return bluePlacementGroup;
    }
}

void PlacementTab::AddUnit(Point p)
{
    auto group = getArmySelected();
    std::string key = group->getSelectedUnit();
    Army army = isRedArmySelected?this->data.getRedArmy():this->data.getBlueArmy();
    if(data.getPlacement().getCount(key,isRedArmySelected) == army.count(UnitProvider::getInstance().getUnit(key)))
    {
        return;
    }
    if(key == "") return;
    this->RemoveUnit(p);
    auto unit = UnitProvider::getInstance().getUnit(key);
    this->data.getPlacement().setPosition(p, std::pair<std::string,bool>(key, isRedArmySelected));
    group->unitAdded(key);
}

void PlacementTab::RemoveUnit(Point p)
{
    if(this->data.getPlacement().hasUnit(p))
    {
        auto key = data.getPlacement().getUnitKey(p).first;
        auto group = getArmySelected();
        this->data.getPlacement().clearPosition(p);
        group->unitRemoved(key);


    }
}

void PlacementTab::DataUpdated()
{
    this->renderer->paintArea();
    this->redPlacementGroup->armyUpdated();
    this->bluePlacementGroup->armyUpdated();
}

void PlacementTab::onSelected(std::string unitId, std::string armyName)
{
    auto unit = UnitProvider::getInstance().getUnit(unitId);
    this->currentSelectedUnit->getLabel()->setPixmap(QPixmap::fromImage(unit.getIcon()).scaled(100,120,Qt::KeepAspectRatio));
    this->currentSelectedUnit->getLabeledLabel()->setText(QString::fromStdString(unitId + "(" + armyName + ")"));
}


#endif // PLACEMENTTAB_CPP
