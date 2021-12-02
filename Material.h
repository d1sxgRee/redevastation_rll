#ifndef MATERIAL_H
#define MATERIAL_H

#include "Coords.h"
#include "Level.h"
#include <string>

class Material{
 protected:
  Coords coords;
  // std::string name;
  // std::string base_description;
  // std::string advd_description;
  // int wisdom_check;
  Level *lvl;
 public:
  Material(Coords coords, Level *lvl) : coords(coords), lvl(lvl){};
  Coords position_get();
  void move(Coords destination);
  // std::string describe(){return base_description;};
};

#endif //MATERIAL_H
