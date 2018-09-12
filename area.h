#ifndef AREA_H
#define AREA_H
#include "jsonwrapper.h"
#include "point.h"
#define AREA_WIDTH 40
#define AREA_HEIGHT 25
class Area {
    int Tiles[AREA_HEIGHT][AREA_WIDTH];
    void toggleFlag(Point p, int flag);

public:

      void read(QJsonValue object);

      int getTile(Point p);
      void toggleTilePassable(Point p);
      void toggleTileSeethrough(Point p);
      void setTile(Point p, int value);
      bool isTilePassable(Point p);
      bool isTileSeethrough(Point p);
      static int getWidth();
      static int getHeight();
      static int getPassableTile();
      static int getSeethroughTile();

      Area(void);

};



template<>
void asInstanceOf<Area>(Area& value,QJsonValue object);
#endif // AREA_H
