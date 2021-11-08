#include "LvlMap.h"
#include <cassert>

size_t LvlMap::from_2d(Coords c){
  size_t i = c.x + c.y * size.x;
  return i;
}

Coords LvlMap::from_1d(size_t i){
  Coords c;
  c.x = i % size.x;
  c.y = i / size.x;
  return c;
}

LvlMap::LvlMap(Coords size):size(size){
  map = new int[size.x * size.y];
}

LvlMap::~LvlMap(){
  delete[] map;
}

void LvlMap::cell_set(Coords cell, int val){
  assert(cell.x < size.x && cell.y < size.y);
  map[from_2d(cell)] = val;
  return;
}

int LvlMap::cell_read(Coords cell){
  assert(cell.x < size.x && cell.y < size.y);
  return map[from_2d(cell)];
}
