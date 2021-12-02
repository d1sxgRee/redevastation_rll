#include "Level.h"

bool Level::can_go(Coords c){
  if(map->cell_read(c) == 0){
    return true;
  }
  return false;
}

void Level::fov_get(Coords c, LvlMap *fov){
  for(int i = c.x - (fov->get_size().x / 2); i <= c.x + (fov->get_size().x / 2); i++){
    for(int j = c.y - (fov->get_size().y / 2); j <= c.y + (fov->get_size().y / 2); j++){
      if(i >= 0 && j >= 0 && i < map->get_size().x && j < map->get_size().y){
        fov->cell_set({i - c.x + (fov->get_size().x / 2), j - c.y + (fov->get_size().y / 2)}, map->cell_read({i, j}));
      }
      else{
        fov->cell_set({i - c.x + (fov->get_size().x / 2), j - c.y + (fov->get_size().y / 2)}, 1);
      }
    }
  }
  return;
}
  
