#include "area.h"
#include "base64.h"

Area::Area(void)
{
    int maxWidth = Area::getWidth();
    int maxHeight = Area::getHeight();
    for(int i = 0; i< maxWidth; i++)
        for(int j =0; j< maxHeight;j++)
            Tiles[j][i] = Area::getPassableTile()|Area::getSeethroughTile();
}

bool Area::isTilePassable(Point p)
{
    if(p.getY() >= Area::getHeight() || p.getX() >= Area::getWidth() || p.getX() < 0 || p.getY()<0 ) return 0;
    return getTile(p)&getPassableTile();
}

int Area::getTile(Point p)
{
    return Tiles[p.getY()][p.getX()];
}

void Area::setTile(Point p,int value)
{
    Tiles[p.getY()][p.getX()] = value;
}

void Area::read(QJsonValue object)
{
    if(object.isString())
    {
        auto str = object.toString();
        auto values = base64_decode(str.toStdString());
        int k = 0;
        for(int i = 0; i< Area::getWidth();i++)
            for(int j = 0;j <Area::getHeight();j++)
            {
                Tiles[j][i] = values[k];
                k++;
            }

    }

}

int Area::getHeight()
{
    static int height = AREA_HEIGHT;
    return height;
}

int Area::getWidth()
{
    static int width = AREA_WIDTH;
    return width;
}

int Area::getPassableTile()
{
    static int PassableTile = 0b1;
    return PassableTile;
}

int Area::getSeethroughTile()
{
    static int SeethroughTile = 0b10;
    return SeethroughTile;
}

inline int getToggledFlag(int value,int flag)
{
    if(value&flag)
    {
        int toSet = ~flag;
        return value&toSet;
    }
    else
    {
        return value|flag;
    }
}

void Area::toggleFlag(Point p, int flag)
{
     this->setTile(p, getToggledFlag(this->getTile(p),flag));
}

void Area::toggleTilePassable(Point p)
{
    printf("%d %d\n",p.getX(),p.getY());
    toggleFlag(p, Area::getPassableTile());
}

void Area::toggleTileSeethrough(Point p)
{
    toggleFlag(p, Area::getSeethroughTile());
}
