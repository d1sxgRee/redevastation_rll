#include "Engine.h"
#include "LvlGenBSP.h"
#include <iostream>

void Engine::new_game_init(){
  fov = new LvlMap({View::view_size, View::view_size});
  for(int x = 0; x < View::view_size; x++){
    for(int y = 0; y < View::view_size; y++){
      fov->cell_set({x, y}, 1);
    }
  }
  fov->dig_rectangle({1, 1}, {View::view_size - 2, View::view_size - 3});

  LvlGen *generator = new LvlGenBSP();
  LvlMap *m = generator->generate({25, 25});
  Level *first_lvl = new Level(m);
  levels.push_back(first_lvl);

  player.move({13, 13});
  player.level_set(levels.back());
  
  return;
}

View Engine::make_step(Command c){
  switch(c){
  case CMD_RIGHT:
    player.go(RIGHT);
    break;
  case CMD_LEFT:
    player.go(LEFT);
    break;
  case CMD_UP:
    player.go(UP);
    break;
  case CMD_DOWN:
    player.go(DOWN);
    break;
  }
  levels.back()->fov_get({player.position_get().x, player.position_get().y}, fov);
  return View(fov);
}
