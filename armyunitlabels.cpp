#include "armyunitlabels.h"
#include "unitprovider.h"
ArmyUnitLabels::ArmyUnitLabels(QWidget * parent, std::function<void(std::string)> onClick) : QWidget(parent)
{
    for(auto& unit : UnitProvider::getInstance().getUnits())
    {

        this->units<< new ArmyUnitLabel(this, unit,onClick);
    }

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addStretch(1);

    foreach(ArmyUnitLabel* item,this->units)
    {

        mainLayout->addWidget(item);

    }
    setLayout(mainLayout);
}
