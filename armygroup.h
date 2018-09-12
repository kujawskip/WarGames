#ifndef ARMYGROUP_H
#define ARMYGROUP_H
#include "army.h"
#include "groupunitlabel.h"
#include <QtWidgets>
class ArmyGroup : public QWidget
{
private:
    Q_OBJECT
    Army& army;
    QHBoxLayout* layout;
    QMap<std::string,GroupUnitLabel*> labels;
public:
    ArmyGroup(QWidget *parent, Army& army, QString name);
    void AddUnit(std::string key);
    void RemoveUnit(std::string key);
    void armyUpdated();
};

#endif // ARMYGROUP_H
