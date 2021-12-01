#ifndef ENGINE_H
#define ENGINE_H

#include "Command.h"
#include "View.h"

class Engine{
 private:
  LvlMap *fov;
 public:
  void new_game_init();
  View make_step(Command c);
  ~Engine(){delete fov;};
};

#endif // ENGINE_H
