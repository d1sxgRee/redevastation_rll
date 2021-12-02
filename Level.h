#ifndef LEVEL_H
#define LEVEL_H

#include "LvlMap.h"
#include <vector>

class Level{
 private:
  LvlMap *map;
 public:
  bool can_go(Coords c);
  void fov_get(Coords c, LvlMap *fov);
  Level() : map(nullptr){};
  explicit Level(LvlMap *map) : map(map){};
  ~Level(){delete map;};
};

#endif // LEVEL_H
