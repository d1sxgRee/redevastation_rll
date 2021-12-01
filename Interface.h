#ifndef INTERFACE_H
#define INTERFACE_H

#include "Engine.h"

class Interface{
 protected:
  Engine *engine;
 public:
  explicit Interface(Engine *engine) : engine(engine){};
  virtual void start() = 0;
};

#endif // INTERFACE_H
