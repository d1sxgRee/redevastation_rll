#include "CursedInterface.h"
#include <ncurses.h>

#define KEY_ESCAPE 27

void CursedInterface::start(){
  initscr();
  keypad(stdscr, TRUE);
  int input = 0;
  do{
    clear();
    mvprintw(10, 10, "@");
    switch(input){
    case 'a':
      mvprintw(0, 0, "WEST");
      break;
    case 'w':
      mvprintw(0, 0, "NORTH");
      break;
    case 'd':
      mvprintw(0, 0, "EAST");
      break;
    case 's':
      mvprintw(0, 0, "SOUTH");
      break;
    default:
      break;
    }
    refresh();
    input = getch();
  }while(input != KEY_ESCAPE);
  endwin();
  return;
}

// LvlGen *generator = new LvlGenBSP;
//   Coords size = {25, 25};
//   LvlMap *map = generator->generate(size);
//   for(int y = 0; y < size.y; y++){
//     for(int x = 0; x < size.x; x++){
//       Coords c = {x, y};
//       switch(map->cell_read(c)){
//       case 0:
//         std::cout << " ";
//         break;
//       case 1:
//         std::cout << "#";
//         break;
//       default:
//         assert(false);
//       }
//     }
//     std::cout << std::endl;
//   }
