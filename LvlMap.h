#ifndef LVLMAP_H
#define LVLMAP_H

#include <cstddef>
#include "Coords.h"

class LvlMap{
 private:
  int *map;
  Coords size;
  size_t from_2d(Coords c);
  Coords from_1d(size_t i);
 public:
  explicit LvlMap(Coords size);
  ~LvlMap();
  void cell_set(Coords cell, int val);
  int cell_read(Coords cell);
  LvlMap(const LvlMap&)=delete;
  LvlMap& operator=(const LvlMap&)=delete;
};

#endif // LVLMAP_H
