#ifndef PLACEMENT_H
#define PLACEMENT_H
#include "jsonwrapper.h"
#include "point.h"
class Placement {

    std::map<Point, std::pair<std::string,bool>> positionsOfUnits;
public:
      void read(QJsonObject& object);
      std::pair<std::string,bool> getUnitKey(Point p);
      bool hasUnit(Point p);
      void setPosition(Point p, std::pair<std::string, bool> unit);
      void clearPosition(Point p);
      int getCount(std::string key, bool value);
      std::vector<Point> getPositions(std::string key,bool value);
};


template<>
void asInstanceOf<Placement>(Placement& value,QJsonValue object);

#endif // PLACEMENT_H
