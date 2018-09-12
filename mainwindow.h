#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "starttab.h"
#include "parameterstab.h"
#include "squadtab.h"
#include "maptab.h"
#include "placementtab.h"
#include "simulationdata.h"
#include "simulationwindow.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
class QSessionManager;
QT_END_NAMESPACE

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
    SimulationData simulationData;
    QTabWidget* tabWidget;
    PlacementTab* placementTab;
    void changeTab(int dIndex);
    void showSimulation();
    SimulationWindow* window;
};
//! [0]

#endif
