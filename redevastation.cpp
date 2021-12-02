#include <iostream>
#include <cassert>
#include "Engine.h"

#ifdef LINUX
#include "CursedInterface.h"
#else
#include "TXLibInterface.h"
#endif

int main(){
  Engine engine;
  engine.new_game_init();
  #ifdef LINUX
  Interface *interface = new CursedInterface(&engine);
  #else
  #endif
  interface->start();
  return 0;
}
