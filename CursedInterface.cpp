#include "CursedInterface.h"
#include <ncurses.h>
#include <cassert>

#define KEY_ESCAPE 27

void CursedInterface::start(){
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  int input = 0;
  View v = engine->make_step(CMD_NOTHING);
  Command cmd;
  do{
    switch(input){
    case 'a':
      cmd = CMD_LEFT;
      break;
    case 'w':
      cmd = CMD_UP;
      break;
    case 'd':
      cmd = CMD_RIGHT;
      break;
    case 's':
      cmd = CMD_DOWN;
      break;
    default:
      cmd = CMD_NOTHING;
      break;
    }
    v = engine->make_step(cmd);
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
    refresh();
    input = getch();
  }while(input != KEY_ESCAPE);
  endwin();
  return;
}




  
