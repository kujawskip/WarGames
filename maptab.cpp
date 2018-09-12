#ifndef MAPTAB_CPP
#define MAPTAB_CPP
#include "maptab.h"
#include "maplist.h"
#include "arearenderer.h"
MapTab::MapTab(QWidget *parent, Area& area)
    : QWidget(parent) , area(area)
{

    auto *mainLayout = new QHBoxLayout;
    areaRenderer = new AreaRenderer(this, this->area, [=](Point p){this->TogglePassable(p);},[=](Point p){this->ToggleSeethrough(p);});
    mainLayout->addStretch(1);
    mainLayout->addWidget(new MapList(this,[=](std::string key){this->LoadArea(key);}));
    mainLayout->addWidget(this->areaRenderer);
    setLayout(mainLayout);

}

void MapTab::TogglePassable(Point p)
{
    this->area.toggleTilePassable(p);
}

void MapTab::ToggleSeethrough(Point p)
{
    this->area.toggleTileSeethrough(p);
}

void MapTab::LoadArea(std::string key)
{
    this->area.read(MapProvider::getInstance().getMap(key));
    this->areaRenderer->paintArea();
}
#endif // MAPTAB_CPP
