#ifndef SQUADTAB_CPP
#define SQUADTAB_CPP
#include "squadtab.h"
SquadTab::SquadTab(QWidget *parent, Army& redArmy,Army& blueArmy)
    : QWidget(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addStretch(1);
    setLayout(mainLayout);

}
#endif // SQUADTAB_CPP
