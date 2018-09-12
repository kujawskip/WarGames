#ifndef AREAANDUNITSRENDERER_H
#define AREAANDUNITSRENDERER_H
#include "arearenderer.h"
#include "placement.h"
class AreaAndUnitsRenderer : public AreaRenderer
{
    Q_OBJECT
    Placement& placement;
public:
    QPoint paintPoint(Point p);
    AreaAndUnitsRenderer(QWidget* parent,Area& area,Placement& placement, std::function<void(Point)> onClick,std::function<void(Point)> onRightClick);

};
#endif // AREAANDUNITSRENDERER_H
