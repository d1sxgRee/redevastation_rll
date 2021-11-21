#include <iostream>
#include <cassert>
#include "LvlGenBSP.h"

int main(){
  LvlGen *generator = new LvlGenBSP;
  Coords size = {50, 50};
  LvlMap *map = generator->generate(size);
  for(int y = 0; y < size.y; y++){
    for(int x = 0; x < size.x; x++){
      Coords c = {x, y};
      switch(map->cell_read(c)){
      case 0:
        std::cout << " ";
        break;
      case 1:
        std::cout << "#";
        break;
      default:
        assert(false);
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
