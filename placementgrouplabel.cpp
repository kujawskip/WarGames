#include "placementgrouplabel.h"
#include <QPixmap>
PlacementGroupLabel::PlacementGroupLabel(QWidget* parent,Unit& unit, std::function<void(std::string)> onClick)

{

    QHBoxLayout *mainLayout = new QHBoxLayout;
    this->onClick = onClick;
    this->UnitImage = new QLabel(this);

    QPixmap pixmap;
    pixmap.convertFromImage(unit.getIcon());

    this->UnitImage->setPixmap(pixmap.scaled(40,80,Qt::KeepAspectRatio));
    this->UnitCount = new QLabel(this);
    this->count = 0;
    this->unitName = unit.getName();
    updateLabel();
    mainLayout->addStretch(1);
    mainLayout->addWidget( this->UnitImage);
    mainLayout->addWidget(this->UnitCount);

    setLayout(mainLayout);
}

void PlacementGroupLabel::updateLabel()
{
    this->UnitCount->setText(QString::fromStdString(std::to_string(count)));
}

void PlacementGroupLabel::mousePressEvent(QMouseEvent *event)
{
    //if somebody presses both buttons, both callbacks will activate
    onClick(this->unitName);

}

void PlacementGroupLabel::unitAdded()
{
    count++;
    updateLabel();
}

void PlacementGroupLabel::unitRemoved()
{
    count--;
    updateLabel();
}

void PlacementGroupLabel::setCount(int count)
{
    count = count;
    updateLabel();
}
