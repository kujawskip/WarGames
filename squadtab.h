#ifndef MAPTAB_H
#define MAPTAB_H
#include "armygroup.h"

class SquadTab : public QWidget
{
    Q_OBJECT

public:
    explicit SquadTab(QWidget *parent, Army& redArmy,Army& blueArmy);
};
#endif // MAPTAB_H
