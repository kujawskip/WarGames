#ifndef UNITLABEL_H
#define UNITLABEL_H
#include <QtWidgets>
#include "unit.h"
class ArmyUnitLabel : public QWidget {
Q_OBJECT
QLabel* UnitImage;
QLabel* UnitName;
std::function<void(std::string)> onClick;
public:
    ArmyUnitLabel(QWidget* parent, Unit& unit, std::function<void(std::string)> onClick);
    void mousePressEvent(QMouseEvent* event);
};
#endif // UNITLABEL_H
