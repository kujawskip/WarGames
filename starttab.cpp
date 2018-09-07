#ifndef STARTTAB_CPP
#define STARTTAB_CPP
#include "starttab.h"
StartTab::StartTab(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addStretch(1);
    setLayout(mainLayout);

}
#endif // STARTTAB_CPP
