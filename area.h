#ifndef AREA_H
#define AREA_H
#include "jsonwrapper.h"
class Area {
public:
      void read(QJsonObject& object);
};

template<>
void asInstanceOf<Area>(Area& value,QJsonValue object);
#endif // AREA_H
