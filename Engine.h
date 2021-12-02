#ifndef ENGINE_H
#define ENGINE_H

#include "Command.h"
#include "View.h"
#include "Level.h"
#include "Creature.h"
#include <list>

class Engine{
 private:
  LvlMap *fov;
  std::list<Level*> levels = {};
 public:
  void new_game_init();
  View make_step(Command c);
  Engine(): levels() {};
  ~Engine(){delete fov;};
};

#endif // ENGINE_H
