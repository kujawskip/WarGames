#ifndef GROUPUNITLABEL_H
#define GROUPUNITLABEL_H
#include <QtWidgets>
#include "unit.h"
class GroupUnitLabel : public QWidget {
Q_OBJECT
QLabel* UnitImage;
QLabel* UnitCount;
std::function<void(std::string)> onClick;
std::function<void(std::string)> onRightClick;
std::string unitName;
int count;
void updateLabel();
public:
    GroupUnitLabel(QWidget* parent, Unit& unit, std::function<void(std::string)> onClick, std::function<void(std::string)> onRightClick, int count);
    void mousePressEvent(QMouseEvent* event);
};
#endif // GROUPUNITLABEL_H
