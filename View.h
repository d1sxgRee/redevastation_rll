#ifndef VIEW_H
#define VIEW_H

#include "LvlMap.h"

class View{
 private:
  LvlMap *map;
 public:
  constexpr static int view_size = 15;
  explicit View(LvlMap *map) : map(map){};
  ~View(){delete map;};
  LvlMap *map_get(){return map;};
};

#endif // VIEW_H
