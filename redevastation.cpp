#include <iostream>
#include <cassert>
#include "CursedInterface.h"
#include "Engine.h"

int main(){
  Engine engine;
  engine.new_game_init();
  Interface *interface = new CursedInterface(&engine);
  interface->start();
  return 0;
}
