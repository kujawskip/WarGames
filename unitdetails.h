#ifndef UNITDETAILS_H
#define UNITDETAILS_H
#include <QtWidgets>
#include <unit.h>
#include <labeledlabel.h>

class UnitDetails : public QWidget
{
    Q_OBJECT
    QLabel* image;
    QLabel* name;
    void handleLabel(LabeledLabel& label, int value);
    LabeledLabel* attackLabel;
    LabeledLabel* movementLabel;
    LabeledLabel* firerateLabel;
    LabeledLabel* rangeLabel;
    LabeledLabel* enduranceLabel;
public:
    UnitDetails(QWidget*);
    void setUnit(Unit unit);
};
#endif // UNITDETAILS_H
