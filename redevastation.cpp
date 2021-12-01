#include <iostream>
#include <cassert>
#include "CursedInterface.h"
#include "Engine.h"

int main(){
  Engine engine;
  Interface *interface = new CursedInterface(&engine);
  interface->start();
  return 0;
}
