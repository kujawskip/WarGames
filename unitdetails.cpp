#include "unitdetails.h"
UnitDetails::UnitDetails(QWidget* parent) : QWidget(parent)
{
    attackLabel =new  LabeledLabel(this);
    rangeLabel = new LabeledLabel(this);
    movementLabel =new LabeledLabel(this);
    firerateLabel =new LabeledLabel(this);
    enduranceLabel = new LabeledLabel(this);
    image = new QLabel(this);
    name = new QLabel(this);

    attackLabel->getLabel()->setText("Obrażenia");
   rangeLabel->getLabel()->setText("Zasięg");
    movementLabel->getLabel()->setText("Ruch");
    firerateLabel->getLabel()->setText("Szybkostrzelność");
    enduranceLabel->getLabel()->setText("Wytrzymałość");

    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->addStretch(1);
    mainLayout->addWidget(image);
    mainLayout->addWidget(name);

    mainLayout->addWidget(enduranceLabel);
    mainLayout->addWidget(attackLabel);
    mainLayout->addWidget(rangeLabel);
    mainLayout->addWidget(movementLabel);
    mainLayout->addWidget(firerateLabel);

    setLayout(mainLayout);
}

void UnitDetails::handleLabel(LabeledLabel &label, int value)
{
    label.getLabeledLabel()->setText(QString::fromStdString(std::to_string(value)));
}

void UnitDetails::setUnit(Unit unit)
{
    this->handleLabel(*enduranceLabel,unit.getEndurance());
    this->handleLabel(*attackLabel, unit.getDamage());
    this->handleLabel(*rangeLabel, unit.getRange());
    this->handleLabel(*movementLabel, unit.getMovement());
    this->handleLabel(*firerateLabel, unit.getFirerate());
    QPixmap pixmap = QPixmap::fromImage(unit.getIcon());

    this->image->setPixmap(pixmap.scaled(90,180, Qt::KeepAspectRatio));
    std::string name = unit.getName();
    this->name->setText(QString::fromStdString(name));
}
