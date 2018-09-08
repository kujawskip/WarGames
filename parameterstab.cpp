#ifndef PARAMETERSTAB_CPP
#define PARAMETERSTAB_CPP
#include "parameterstab.h"
#include "labeledslider.h"
#include "labeledlineedit.h"
#include "vector_from_array.h"
ParametersTab::ParametersTab(QWidget *parent, SimulationParameters& parameters)
    : QWidget(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    this->parameters = parameters;
    std::vector<int> accSliderValuesVector;
    std::vector<int> dmgSliderValuesVector;
    std::vector<int> spdSliderValuesVector;
    initVectorFromArray<int>(accSliderValuesVector, accuracyValues);
    initVectorFromArray<int>(dmgSliderValuesVector, damageValues);
    initVectorFromArray<int>(spdSliderValuesVector, speedValues);
    LabeledSlider* accuracySlider = new LabeledSlider(this, accSliderValuesVector,[=](int a) {this->parameters.setAccuracy(a);},  "Celność",""," %");
    LabeledSlider* damageSlider = new LabeledSlider(this, dmgSliderValuesVector,[=](int a) {this->parameters.setDamage(a);},  "Obrażenia",""," %");
    LabeledSlider* speedSlider = new LabeledSlider(this, spdSliderValuesVector,[=](int a) {this->parameters.setSpeed(a);},  "Szybkość",""," %");
    LabeledLineEdit* seedEditor = new LabeledLineEdit(this,[=](const QString& a) {this->parameters.setSeed(a.toStdString());}  );
    auto button = new QPushButton("Rozpocznij",this);
    mainLayout->addStretch(1);
    mainLayout->addWidget(accuracySlider);
    mainLayout->addWidget(damageSlider);
    mainLayout->addWidget(speedSlider);
    mainLayout->addWidget(seedEditor);
    mainLayout->addWidget(button);
    setLayout(mainLayout);

}
#endif // PARAMETERSTAB_CPP
