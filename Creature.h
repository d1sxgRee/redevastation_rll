#ifndef CREATURE_H
#define CREATURE_H

#include "Material.h"
#include "Level.h"
#include "Direction.h"

class Creature : public Material{
 protected:
  int health_max = 1;
  int health = 1;
  int mana_max = 1;
  int mana = 1;
  int strength = 0;
  int intelegence = 0;
  int dexterity = 0;
  int wisdom = 0;
 public:
  void go(Direction d);
  void level_set(Level *lvl){this->lvl = lvl;};
  explicit Creature(Coords coords, Level *lvl) : Material(coords, lvl){};
};

#endif // CREATURE_H
