#include "placementgroup.h"
#include "unitprovider.h"
PlacementGroup::PlacementGroup(QWidget *parent, Army &army,Placement& placement,std::function<void(std::string)> onSelected, QString name)
    :QWidget(parent), army(army), placement(placement)
{

    this->onSelected = onSelected;
    this->isRedArmy = name == "Armia pierwsza";
    auto mainLayout = new QVBoxLayout;
    mainLayout->addStretch(1);
    mainLayout->addWidget(new QLabel(name,this));
    auto armyLayout = new QHBoxLayout;
    armyLayout->addStretch(1);
    for(auto& soldier : UnitProvider::getInstance().getUnits())
    {
        auto label = new PlacementGroupLabel(this, soldier, [=](std::string key){this->selectedUnit = key ;this->onSelected(key);});
        labels.insert(soldier.getName(), label );
        armyLayout->addWidget(label);
    }
    mainLayout->addLayout(armyLayout);
    this->setLayout(mainLayout);
}

void PlacementGroup::armyUpdated()
{
    for(auto& unit : UnitProvider::getInstance().getUnits())
    {
        this->labels[unit.getName()]->setCount(this->army.count(unit) - this->placement.getCount(unit.getName(), isRedArmy));
    }
}

void PlacementGroup::unitAdded(std::string unit)
{
    this->labels[unit]->unitAdded();
}

void PlacementGroup::unitRemoved(std::string unit)
{
    this->labels[unit]->unitRemoved();
}

std::string PlacementGroup::getSelectedUnit()
{
    return selectedUnit;
}
