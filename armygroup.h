#ifndef ARMYGROUP_H
#define ARMYGROUP_H
#include "army.h"
#include <QtWidgets>
class ArmyGroup : public QWidget
{
private:
    Q_OBJECT
    Army army;
public:
    explicit ArmyGroup(QWidget *parent, Army& army);
    void ArmyUpdated();
};

#endif // ARMYGROUP_H
