#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "starttab.h"
#include "parameterstab.h"
#include "squadtab.h"
#include "maptab.h"
#include "placementtab.h"



QT_BEGIN_NAMESPACE
aclass QAction;
class QMenu;
class QPlainTextEdit;
class QSessionManager;
QT_END_NAMESPACE

class Area {
};
class Placement {
};
class Army {
};
class SimulationData {
    Area area;
    Army redArmy;
    Army blueArmy;
    Placement placement;
    SimulatedParameters parameters;
    public:
    Area& getArea();
    Army& getRedArmy();
    Army& getBlueArmy();
    Placement& getPlacement();
    SimulatedParameters& getParameters();
};

Area& SimulationData::getArea() {
return this->area;
}

Army& SimulationData::getRedArmy()
{
    return this->redArmy;
}

Army& SimulationData::getBlueArmy()
{
    return this->blueArmy;
}

Placement& SimulationData::getPlacement() {
return this->placement;
}

SimulatedParameters& SimulationData::getParameters()
{
    return this->parameters;
}

SimulationData::SimulationData()
{
    this->parameters = Parameters();
    this->redArmy = Army();
    this->blueArmy = Army();
    this->area = Area();
    this->placement = Placement();
}

//! [0]
class MainWindow : public QMainWindow
{


public:
    MainWindow();
public slots:
    void onTabChanged(int Index);
    void onNextClicked();
    void onPreviousClicked();
private:
    Q_OBJECT
    QPushButton* previousButton, *nextButton;
    SimulationData* simulationData;
    QTabWidget* tabWidget;
    void changeTab(int dIndex);

};
//! [0]

#endif
