#ifndef SIMUNITDETAILS_H
#define SIMUNITDETAILS_H
#include <QtWidgets>
#include <simulatedunit.h>
#include <labeledlabel.h>
#include <simulationsnapshot.h>
class SimulatedUnitDetails : public QWidget
{
    Q_OBJECT
    QLabel* image;
    QLabel* name;
    SimulationSnapshot snapshot;
    Point point;
    bool snapshotSet;
    bool pointSet;
    void handleLabel(LabeledLabel& label, int value);
    LabeledLabel* currentHPLabel;
    LabeledLabel* attackLabel;
    LabeledLabel* movementLabel;
    LabeledLabel* firerateLabel;
    LabeledLabel* rangeLabel;
    LabeledLabel* enduranceLabel;
    void setUnit();
public:
    SimulatedUnitDetails(QWidget*);
    void setSnapshot(SimulationSnapshot snapshot);
    void setPoint(Point p);
};
#endif // UNITDETAILS_H
