#include "TXLibInterface.h"
#include "TXLib.h"

void TXLibInterface::start(){
  txCreateWindow(300, 300);
  HDC playericon = txLoadImage("res\\hero_icon.bmp");
  int heroicon_size = 16;
  HDC wallssprite = txLoadImage("res\\dungeon_walls.bmp");
  HDC floorsprite = txLoadImage("res\\dungeon_floor.bmp");
  int terreinsprite_size = 20;
  View v = engine->make_step(CMD_NOTHING);
  Command cmd;
  txBegin();
  do{

    if(GetAsyncKeyState(0x41)){
      cmd = CMD_LEFT;
    }
    else if(GetAsyncKeyState(0x57)){
      cmd = CMD_UP;
    }
    else if(GetAsyncKeyState(0x44)){
      cmd = CMD_RIGHT;
    }
    else if(GetAsyncKeyState(0x53)){
      cmd = CMD_DOWN;
    }
    else{
      cmd = CMD_NOTHING;
    }
      
    v = engine->make_step(cmd);
    
    txClear();
    for(int y = 0; y < View::view_size; y++){
      for(int x = 0; x < View::view_size; x++){
        Coords c = {x, y};
        switch(v.map_get()->cell_read(c)){
        case 0:
          txTransparentBlt(txDC(),
                           x * terreinsprite_size,
                           y * terreinsprite_size,
                           terreinsprite_size,
                           terreinsprite_size,
                           floorsprite,
                           0,
                           0,
                           RGB(0, 255, 0));
          break;
        case 1:
          txTransparentBlt(txDC(),
                           x * terreinsprite_size,
                           y * terreinsprite_size,
                           terreinsprite_size,
                           terreinsprite_size,
                           wallssprite,
                           0,
                           0,
                           RGB(0, 255, 0));
          break;
        default:
          break;
        }
      }
    }
    txTransparentBlt(txDC(),
                     View::view_size / 2 * terreinsprite_size + (terreinsprite_size - heroicon_size) / 2,
                     View::view_size / 2 * terreinsprite_size + (terreinsprite_size - heroicon_size) / 2,
                     heroicon_size,
                     heroicon_size,
                     playericon,
                     0,
                     0,
                     RGB(0, 255, 0));
    txSleep(100);
  }while(!GetAsyncKeyState(VK_ESCAPE));
  txEnd();
  txDeleteDC(playericon);
  txDeleteDC(wallssprite);
  txDeleteDC (floorsprite);
  return;
}
