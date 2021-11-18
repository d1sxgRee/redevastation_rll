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

void LvlMap::dig_rectangle(Coords start, Coords end){
  assert(start.x >= 0);
  assert(start.x < size.x);
  assert(start.y >= 0);
  assert(start.y < size.y);
  assert(end.x >= 0);
  assert(end.x < size.x);
  assert(end.y >= 0);
  assert(end.y < size.y);
  assert(start.x <= end.x);
  assert(start.y <= end.y);
  Coords i = start;
  while(i.x <= end.x && i.y <= end.y){
    cell_set(i, 0);
    i.x ++;
    if(i.x > end.x){
      i.x = start.x;
      i.y ++;
    }
  }
  return;
}
