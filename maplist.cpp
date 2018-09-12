#include "maplist.h"
#include "mapprovider.h"

MapList::MapList(QWidget *parent, std::function<void (std::string)> onClick)
{
    auto list = MapProvider::getInstance().getMapList();
    QVBoxLayout* layout = new QVBoxLayout(this);
    this->onClick = onClick;
    for(auto& listItem : list)
    {
        QString qName = QString::fromStdString(listItem);
        auto button = new QPushButton(qName,this);
        button->setObjectName(qName);
        connect(button, &QPushButton::clicked,this, &MapList::HandleButtonPress );
        layout->addWidget(button);
        layout->setAlignment(button,Qt::AlignLeft|Qt::AlignTop);

        maps.append(button);

    }
    this->setLayout(layout);
}

void MapList::HandleButtonPress()
{
    QObject *senderObj = sender(); // This will give Sender object
    QString senderObjName = senderObj->objectName();
    this->onClick(senderObjName.toStdString());
}
