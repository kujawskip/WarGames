#include "area.h"
#include "base64.h"

Area::Area(void)
{
    for(int i = 0; i< width; i++)
        for(int j =0; j< height;j++)
            Tiles[i][j] = 0;
}

int Area::getTile(Point p)
{
    return Tiles[p.getX()][p.getY()];
}

void Area::setTile(Point p,int value)
{
    Tiles[p.getX()][p.getY()] = value;
}

void Area::read(QJsonValue &object)
{
    if(object.isString())
    {
        auto str = object.toString();
        auto values = base64_decode(str.toStdString());
        int k = 0;
        for(int i = 0; i< width;i++)
            for(int j = 0;j <height;j++)
            {
                Tiles[i][j] = values[k];
                k++;
            }

    }

}
