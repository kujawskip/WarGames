#ifndef SQUADTAB_CPP
#define SQUADTAB_CPP
#include "squadtab.h"
#include "armyunitlabels.h"
#include "unitdetails.h"
#include "unitprovider.h"
#include "armygroup.h"
SquadTab::SquadTab(QWidget *parent, Army& redArmy,Army& blueArmy)
    : QWidget(parent)
{

    QHBoxLayout *mainLayout = new QHBoxLayout;

    ArmyUnitLabels *labels = new ArmyUnitLabels(this, [=](std::string key){this->selectedUnit = UnitProvider::getInstance().getUnit(key); details->setUnit(this->selectedUnit);  });

    details = new UnitDetails(this);

    mainLayout->addStretch(1);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setAlignment(Qt::AlignLeft);
    mainLayout->addWidget(labels);
    mainLayout->addWidget(details);
    QVBoxLayout *armiesLayout = new QVBoxLayout;
    armiesLayout->addWidget(new ArmyGroup(this,redArmy, "Armia pierwsza"));
    armiesLayout->addWidget(new ArmyGroup(this,blueArmy, "Armia druga"));

    mainLayout->addLayout(armiesLayout);
    setLayout(mainLayout);

}
#endif // SQUADTAB_CPP
