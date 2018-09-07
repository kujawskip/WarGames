#ifndef PLACEMENTTAB_CPP
#define PLACEMENTTAB_CPP
#include "placementtab.h"
PlacementTab::PlacementTab(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addStretch(1);
    setLayout(mainLayout);

}
#endif // PLACEMENTTAB_CPP
