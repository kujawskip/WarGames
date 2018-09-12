#include "areaandunitsrenderer.h"
#include "unitprovider.h"
AreaAndUnitsRenderer::AreaAndUnitsRenderer(QWidget *parent, Area &area, Placement &placement, std::function<void (Point)> onClick, std::function<void (Point)> onRightClick) : AreaRenderer(parent,area,onClick,onRightClick,false), placement(placement)
{

}

QPoint AreaAndUnitsRenderer::paintPoint(Point p)
{
    auto pos = AreaRenderer::paintPoint(p);
    if(placement.hasUnit(p))
    {
        auto unitInfo = placement.getUnitKey(p);
        auto unit = UnitProvider::getInstance().getUnit(unitInfo.first);
        auto texture = QPixmap::fromImage(unit.getIcon());
        if(!unitInfo.second)
        {
         QTransform transform;
         auto trans = transform.rotate(180);
         texture = QPixmap(texture.transformed(trans));

        }
        this->painter->drawPixmap(pos,texture.scaled(getWidth()/Area::getWidth(),getHeight()/Area::getHeight(),Qt::KeepAspectRatio));
    }
    return pos;
}
