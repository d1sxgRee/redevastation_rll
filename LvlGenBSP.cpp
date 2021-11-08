#include "LvlGenBSP.h"

LvlMap *LvlGenBSP::generate(Coords size){
  LvlMap *map = new LvlMap(size);
  for(int y = 0; y < size.y; y++){
    for(int x = 0; x < size.x; x++){
      Coords c = {x, y};
      map->cell_set(c, 1);
    }
  }
  return map;
}
