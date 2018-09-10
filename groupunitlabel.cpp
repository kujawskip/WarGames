#include "groupunitlabel.h"
#include <QPixmap>
GroupUnitLabel::GroupUnitLabel(QWidget* parent,Unit& unit, std::function<void(std::string)> onClick, std::function<void(std::string)> onRightClick, int count) : QWidget(parent)
{

    QHBoxLayout *mainLayout = new QHBoxLayout;
    this->onClick = onClick;
    this->UnitImage = new QLabel(this);
    this->onRightClick = onRightClick;
    QPixmap pixmap;
    pixmap.convertFromImage(unit.getIcon());

    this->UnitImage->setPixmap(pixmap.scaled(40,80,Qt::KeepAspectRatio));
    this->UnitCount = new QLabel(this);
    this->count = count;
    this->unitName = unit.getName();
    updateLabel();
    mainLayout->addStretch(1);
    mainLayout->addWidget( this->UnitImage);
    mainLayout->addWidget(this->UnitCount);

    setLayout(mainLayout);
}

void GroupUnitLabel::updateLabel()
{
    this->UnitCount->setText(QString::fromStdString(std::to_string(count)));
}

void GroupUnitLabel::mousePressEvent(QMouseEvent *event)
{
    //if somebody presses both buttons, both callbacks will activate
    if(event->button() == Qt::LeftButton)
    {
        onClick(this->unitName);
        count++;
    }
    if(event->button() == Qt::RightButton)
    {
        onRightClick(this->unitName);
        if(count>=1) count--;
    }
    updateLabel();
}
