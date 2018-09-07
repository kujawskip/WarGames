#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "starttab.h"
#include "parameterstab.h"
#include "squadtab.h"
#include "maptab.h"
#include "placementtab.h"

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
    SimulationParameters* simulationParameters;
    QTabWidget* tabWidget;
    void changeTab(int dIndex);

};
//! [0]

#endif
