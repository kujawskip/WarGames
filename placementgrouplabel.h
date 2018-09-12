#ifndef PLACGROUPUNITLABEL_H
#define  PLACGROUPUNITLABEL_H
#include <QtWidgets>
#include "unit.h"
class PlacementGroupLabel : public QWidget {
    Q_OBJECT
    QLabel* UnitImage;
    QLabel* UnitCount;
    std::function<void(std::string)> onClick;

    std::string unitName;
    int count;
    void updateLabel();
public:
    PlacementGroupLabel(QWidget* parent, Unit& unit, std::function<void(std::string)> onClick);
    void mousePressEvent(QMouseEvent* event);
    void unitAdded();
    void unitRemoved();
    void setCount(int count);
};
#endif // GROUPUNITLABEL_H
