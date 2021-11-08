#ifndef LVLGEN_H
#define LVLGEN_H

#include "LvlMap.h"

class LvlGen{
 public:
  virtual LvlMap *generate(Coords size) = 0;
};

#endif // LVLGEN_H
