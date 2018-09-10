#include "labeledlabel.h"
LabeledLabel::LabeledLabel(QWidget *parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    this->label = new QLabel(this);
    this->labeledLabel = new QLabel(this);




    mainLayout->addStretch(1);
    mainLayout->addWidget(label);
    mainLayout->addWidget(labeledLabel);

    setLayout(mainLayout);
}


QLabel* LabeledLabel::getLabel()
{
    return label;
}

QLabel* LabeledLabel::getLabeledLabel()
{
    return labeledLabel;
}
