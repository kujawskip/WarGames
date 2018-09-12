#include "simulationwindow.h"

SimulationWindow::SimulationWindow(SimulationData &data) : QMainWindow()
{
    this->simulation = Simulation(data);
    auto container = new QGroupBox;
    auto* layout = new QHBoxLayout(container);
    auto* mapLayout = new QVBoxLayout;

    this->renderer = new SimulationRenderer(this, simulation.getSnapshot(0), [=](Point p){pointClicked(p);});
    auto* sideLayout = new QVBoxLayout;
   this->details = new SimulatedUnitDetails(this);
    this->iterationSlider = new QSlider(Qt::Horizontal,this);
    iterationSlider->setMaximum(this->simulation.getCount() - 1);
    iterationSlider->setTickInterval(1);
    iterationSlider->setMinimum(0);
    layout->setSpacing(0);
    layout->setMargin(0);
    connect(iterationSlider, &QSlider::valueChanged,this,&SimulationWindow::setSnapshot);
   this->redGroup = new SimulationUnitGroup(this, simulation.getSnapshot(0),"Armia pierwsza",0);
    this->blueGroup = new SimulationUnitGroup(this, simulation.getSnapshot(0),"Armia druga",1);

    mapLayout->setSpacing(0);
    mapLayout->setMargin(0);
    mapLayout->addWidget(renderer);
    mapLayout->addStretch(1);


    mapLayout->addWidget(this->iterationSlider);

   sideLayout->addWidget(redGroup);
    sideLayout->addWidget(blueGroup);
   sideLayout->addWidget(details);

    layout->addLayout(mapLayout);
    layout->addLayout(sideLayout);
    setCentralWidget(container);
    setSnapshot(0);
}

void SimulationWindow::setSnapshot(int snapshotId)
{
    auto snapshot = this->simulation.getSnapshot(snapshotId);
    this->renderer->setSnapshot(snapshot);
    this->details->setSnapshot(snapshot);
    this->redGroup->setSnapshot(snapshot);
    this->blueGroup->setSnapshot(snapshot);
}

void SimulationWindow::pointClicked(Point p)
{
    this->details->setPoint(p);
}
