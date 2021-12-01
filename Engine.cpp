#include "Engine.h"

void Engine::new_game_init(){
  fov = new LvlMap({View::view_size, View::view_size});
  for(int x = 0; x < View::view_size; x++){
    for(int y = 0; y < View::view_size; y++){
      fov->cell_set({x, y}, 1);
    }
  }
  return;
}

View Engine::make_step(Command c){
  return View(fov);
}