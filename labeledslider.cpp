#include "labeledslider.h"

LabeledSlider::LabeledSlider(QWidget *parent, std::vector<int> values,std::function<void(int)> callBack, std::string label ,std::string prefix, std::string suffix) : QWidget(parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    this->values = std::vector<int>(values);
    this->prefix = std::string(prefix);
    this->suffix = std::string(suffix);
    QLabel* labelWidget = new QLabel(this);
    labelWidget->setText(QString::fromStdString(label));
    slider = new QSlider(Qt::Horizontal,this);
    slider->setMinimum(0);
    slider->setMaximum(values.size()-1);
    valueLabel = new QLabel(this);
    connect(slider, SIGNAL(valueChanged(int)),this, SLOT(onValueChanged(int)));
    onValueChanged(0);
    mainLayout->addStretch(1);
    mainLayout->addWidget(labelWidget);
    mainLayout->addWidget(slider);
    mainLayout->addWidget(valueLabel);
    setLayout(mainLayout);
}

int LabeledSlider::getValue()
{
    return values[slider->value()];
}

std::string LabeledSlider::getLabel()
{
    std::string label = prefix + std::to_string(this->getValue()) + suffix;

    return label;
}

void LabeledSlider::onValueChanged(int value)
{
    this->valueLabel->setText(QString::fromStdString(this->getLabel()));
}
