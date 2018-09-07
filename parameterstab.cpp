#ifndef PARAMETERSTAB_CPP
#define PARAMETERSTAB_CPP
#include "parameterstab.h"
#include "labeledslider.h"
#include "helper.h"
ParametersTab::ParametersTab(QWidget *parent, SimulationParameters* parameters)
    : QWidget(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout;

    std::vector<int> accSliderValuesVector;
    initVectorFromArray<int>(accSliderValuesVector, accuracyValues);
    LabeledSlider* accuracySlider = new LabeledSlider(this, accSliderValuesVector,[=](int a) {parameters->setAccuracy(a);},  "Celność",""," %");
    mainLayout->addStretch(1);
    mainLayout->addWidget(accuracySlider);

    setLayout(mainLayout);

}
#endif // PARAMETERSTAB_CPP
