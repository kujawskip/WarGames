#ifndef PLACEMENT_H
#define PLACEMENT_H
#include "jsonwrapper.h"
class Placement {
public:
      void read(QJsonObject& object);
};


template<>
void asInstanceOf<Placement>(Placement& value,QJsonValue object);

#endif // PLACEMENT_H
