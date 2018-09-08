#include "labeledlineedit.h"

LabeledLineEdit::LabeledLineEdit(QWidget *parent, std::function<void(const QString&)> callBack, std::string label) : QWidget(parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    this->callBack = callBack;
    QLabel* labelWidget = new QLabel(this);
    labelWidget->setText(QString::fromStdString(label));
    slider = new QLineEdit(this);
    connect(slider, SIGNAL(textChanged(const QString&)),this, SLOT(onValueChanged(const QString&)));
    onValueChanged(0);
    mainLayout->addStretch(1);
    mainLayout->addWidget(labelWidget);
    mainLayout->addWidget(slider);
    setLayout(mainLayout);
}

QString LabeledLineEdit::getValue()
{
    return slider->text();
}

void LabeledLineEdit::onValueChanged(const QString& value)
{
    callBack(value);
}
