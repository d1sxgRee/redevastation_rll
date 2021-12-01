#include "CursedInterface.h"
#include <ncurses.h>
#include <cassert>

#define KEY_ESCAPE 27

void CursedInterface::start(){
  initscr();
  keypad(stdscr, TRUE);
  int input = 0;
  View v = engine->make_step(CMD_NOTHING);
  Command c;
  do{
    clear();
    for(int y = 0; y < View::view_size; y++){
      for(int x = 0; x < View::view_size; x++){
        Coords c = {x, y};
        switch(v.map_get()->cell_read(c)){
        case 0:
          mvprintw(y, x, ".");
          break;
        case 1:
          mvprintw(y, x, "#");
          break;
        default:
          assert(false);
        }
      }
    }
    mvprintw(View::view_size / 2, View::view_size / 2, "@");
    switch(input){
    case 'a':
      c = CMD_LEFT;
      break;
    case 'w':
      c = CMD_UP;
      break;
    case 'd':
      c = CMD_RIGHT;
      break;
    case 's':
      c = CMD_DOWN;
      break;
    default:
      c = CMD_NOTHING;
      break;
    }
    v = engine->make_step(c);
    refresh();
    input = getch();
  }while(input != KEY_ESCAPE);
  endwin();
  return;
}




  
