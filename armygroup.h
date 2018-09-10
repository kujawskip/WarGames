#ifndef ARMYGROUP_H
#define ARMYGROUP_H
#include "army.h"
#include <QtWidgets>
class ArmyGroup : public QWidget
{
private:
    Q_OBJECT
    Army army;
    QHBoxLayout* layout;
public:
    ArmyGroup(QWidget *parent, Army& army, QString name);
    void AddUnit(std::string key);
    void RemoveUnit(std::string key);
    
};

#endif // ARMYGROUP_H
