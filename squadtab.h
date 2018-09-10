#ifndef MAPTAB_H
#define MAPTAB_H
#include "armygroup.h"
#include "unitdetails.h"
class SquadTab : public QWidget
{
    Q_OBJECT
UnitDetails * details;
Unit selectedUnit;
public:
    explicit SquadTab(QWidget *parent, Army& redArmy,Army& blueArmy);
};
#endif // MAPTAB_H
