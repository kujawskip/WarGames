#include "simulationunitgroup.h"
#include "unitprovider.h"
void SimulationUnitGroup::setSnapshot(SimulationSnapshot snapshot)
{
    for(auto& soldier : UnitProvider::getInstance().getUnits())
    {
        auto label = labels[soldier.getName()];
        label->setCount(snapshot.getCount(soldier.getName(),army));

    }
}

SimulationUnitGroup::SimulationUnitGroup(QWidget *parent, SimulationSnapshot snapshot, QString name, int army) : QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch(1);
    mainLayout->addWidget(new QLabel(name,this));
    QHBoxLayout* armyLayout = new QHBoxLayout;
    this->army = army;
    for(auto& soldier : UnitProvider::getInstance().getUnits())
    {
        auto label = new PlacementGroupLabel(this, soldier, [=](std::string key){});
        label->setCount(snapshot.getCount(soldier.getName(),army));
        labels.insert(soldier.getName(), label );
        armyLayout->addWidget(label);
    }
   // this->army = army;
    mainLayout->addLayout(armyLayout);
    setLayout(mainLayout);
}
