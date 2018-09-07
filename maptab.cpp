#ifndef MAPTAB_CPP
#define MAPTAB_CPP
#include "maptab.h"
MapTab::MapTab(QWidget *parent, Area& area)
    : QWidget(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addStretch(1);
    setLayout(mainLayout);

}
#endif // MAPTAB_CPP
