#include "armygroup.h"
#include "unitprovider.h"
#include "groupunitlabel.h"
Unit getUnit(std::string key)
{
    return UnitProvider::getInstance().getUnit(key);
}


ArmyGroup::ArmyGroup(QWidget *parent, Army &passedArmy, QString name) :QWidget(parent)
{

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch(1);
    mainLayout->addWidget(new QLabel(name,this));
    QHBoxLayout* armyLayout = new QHBoxLayout;
    for(auto& soldier : UnitProvider::getInstance().getUnits())
    {
        armyLayout->addWidget(new GroupUnitLabel(this, soldier, [=](std::string key){this->AddUnit(key);}, [=](std::string key){this->RemoveUnit(key);}, passedArmy.count(soldier)));
    }
   // this->army = army;
    mainLayout->addLayout(armyLayout);
    setLayout(mainLayout);
}

void ArmyGroup::AddUnit(std::string key)
{
    this->army.add(getUnit(key));
}
void ArmyGroup::RemoveUnit(std::string key)
{
    this->army.remove(getUnit(key));
}

