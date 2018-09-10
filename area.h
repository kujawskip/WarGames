#ifndef AREA_H
#define AREA_H
#include "jsonwrapper.h"
#include "point.h"
#define AREA_WIDTH 40
#define AREA_HEIGHT 25
class Area {
    int Tiles[AREA_HEIGHT][AREA_WIDTH];
    const int width = AREA_WIDTH;
    const int height = AREA_HEIGHT;
public:
      void read(QJsonValue& object);
      const int PassableTile = 1;
      const int SeethroughTile = 0x10;
      int getTile(Point p);
      void toggleTilePassable(Point p);
      void toggleTileSeethrough(Point p);
      void setTile(Point p, int value);
      bool isTilePassable(Point p);
      bool isTileSeethrough(Point p);
      Area(void);
};



template<>
void asInstanceOf<Area>(Area& value,QJsonValue object);
#endif // AREA_H
