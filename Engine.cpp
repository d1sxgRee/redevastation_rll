#include "Engine.h"
#include "LvlGenBSP.h"

void Engine::new_game_init(){
  fov = new LvlMap({View::view_size, View::view_size});
  for(int x = 0; x < View::view_size; x++){
    for(int y = 0; y < View::view_size; y++){
      fov->cell_set({x, y}, 1);
    }
  }
  fov->dig_rectangle({1, 1}, {View::view_size - 2, View::view_size - 3});

  LvlGen *generator = new LvlGenBSP();
  LvlMap *m = generator->generate({50, 50});
  Level *first_lvl = new Level(m);
  levels.push_back(first_lvl);
  
  return;
}

View Engine::make_step(Command c){
  return View(fov);
}
