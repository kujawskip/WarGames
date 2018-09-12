

#include <QtWidgets>
#include "simulationwindow.h"
#include "mainwindow.h"
#include "parameters.h"
#include "unitprovider.h"
#include "jsonwrapper.h"
#include "mapprovider.h"
void MainWindow::onTabChanged(int tabIndex) {
    this->previousButton->setEnabled(tabIndex > 0);
    this->nextButton->setEnabled(tabIndex < (this->tabWidget->count()-1));
    if(tabWidget->indexOf(this->placementTab) == tabIndex ) this->placementTab->DataUpdated();
}

void MainWindow::changeTab(int dIndex)
{
    int currentTab = this->tabWidget->currentIndex();
    int count = this->tabWidget->count();
    currentTab += dIndex;
    currentTab = currentTab < 0? 0 : (currentTab >= count? count - 1 : currentTab );
    this->tabWidget->setCurrentIndex(currentTab);

}

void MainWindow::onNextClicked() {
    this->changeTab(1);
}

void MainWindow::onPreviousClicked() {
    this->changeTab(-1);
}


MainWindow::MainWindow()

//! [1] //! [2]
{

    auto unitsJson = loadJson(":/units.json");
    auto mapsJson = loadJson(":/maps.json");
    UnitProvider::getInstance().load(unitsJson.object());
    MapProvider::getInstance().load(mapsJson.object());
    auto container = new QGroupBox;
    container->setMinimumWidth(500);
    container->setMinimumHeight(500);
    QVBoxLayout *layout = new QVBoxLayout(container);

    auto buttonContainer = new QGroupBox(container);
    buttonContainer->setMinimumHeight(100);
    buttonContainer->setMinimumWidth(200);
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonContainer);
    this->placementTab = new PlacementTab(this,this->simulationData);
    tabWidget = new QTabWidget(container);

    tabWidget->addTab(new StartTab(this),"Start");

    tabWidget->addTab(new SquadTab(this, this->simulationData.getRedArmy(), this->simulationData.getBlueArmy()),"Oddziały");
    tabWidget->addTab(new MapTab(this, this->simulationData.getArea()),"Mapa");
    tabWidget->addTab(this->placementTab,"Rozmieszczenie");
    tabWidget->addTab(new ParametersTab(this,this->simulationData.getParameters(), [=](){this->showSimulation();}),"Parametry");
    connect(tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));
    previousButton = new QPushButton("Wstecz",buttonContainer);
    nextButton = new QPushButton("Dalej",buttonContainer);
    connect(nextButton, SIGNAL(clicked(bool)),this, SLOT(onNextClicked()));
    connect(previousButton, SIGNAL(clicked(bool)),this, SLOT(onPreviousClicked()));
    layout->addWidget(tabWidget);
    layout->addWidget(buttonContainer);
    container->setLayout(layout);
    buttonLayout->addWidget(previousButton);
    buttonLayout->addWidget(nextButton);
    buttonContainer->setLayout(buttonLayout);
    onTabChanged(0);
    setCentralWidget(container);

}

void MainWindow::showSimulation()
{
    this->window =new SimulationWindow(simulationData);
    window->show();
}

