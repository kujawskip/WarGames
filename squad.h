#ifndef SQUAD_H
#define SQUAD_H
#include <vector>
#include <simulatedunit.h>
#include <point.h>
class Squad {
  vector<SimulatedUnit> Units;
  Point& DefenseTarget;
public:
  void AddSimulatedUnit(SimulatedUnit& unit);
  void AddUnit(Unit& unit);
  bool hasTarget();
  Point getTarget();
};
#endif // SQUAD_H
