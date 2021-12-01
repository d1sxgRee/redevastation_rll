#include "Level.h"

bool Level::can_go(Coords c){
  if(map->cell_read(c) == 0){
    return true;
  }
  return false;
}

