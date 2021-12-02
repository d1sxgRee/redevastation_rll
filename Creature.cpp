#include "Creature.h"

void Creature::go(Direction d){
  Coords c1;
  switch(d){
  case RIGHT:
    c1 = {coords.x + 1, coords.y};
    break;
  case LEFT:
    c1 = {coords.x - 1, coords.y};
    break;
  case UP:
    c1 = {coords.x, coords.y - 1};
    break;
  case DOWN:
    c1 = {coords.x, coords.y + 1};
    break;
  }
  if(lvl->can_go(c1)){
    coords = c1;
  }
  return;
}
