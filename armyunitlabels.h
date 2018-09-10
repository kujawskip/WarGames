#ifndef UNITLABELS_H
#define UNITLABELS_H
#include <QtWidgets>
#include "armyunitlabel.h"
#include <vector>
class ArmyUnitLabels : public QWidget
{
    Q_OBJECT
    QList<ArmyUnitLabel*> units;
public:
    ArmyUnitLabels(QWidget* parent, std::function<void(std::string)> onClick);
};
#endif // UNITLABELS_H
