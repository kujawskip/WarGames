#include "armyunitlabel.h"
#include <QPixmap>
ArmyUnitLabel::ArmyUnitLabel(QWidget* parent,Unit& unit, std::function<void(std::string)> onClick) : QWidget(parent)
{

    QHBoxLayout *mainLayout = new QHBoxLayout;
    this->onClick = onClick;
    this->UnitImage = new QLabel(this);
    QPixmap pixmap;
    pixmap.convertFromImage(unit.getIcon());

    this->UnitImage->setPixmap(pixmap.scaled(40,80,Qt::KeepAspectRatio));
    this->UnitName = new QLabel(this);
    this->UnitName->setText(QString::fromStdString(unit.getName()));
    mainLayout->addStretch(1);
    mainLayout->addWidget( this->UnitImage);
    mainLayout->addWidget(this->UnitName);

    setLayout(mainLayout);
}

void ArmyUnitLabel::mousePressEvent(QMouseEvent *event)
{
    this->onClick(this->UnitName->text().toStdString());
}
