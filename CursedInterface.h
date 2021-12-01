#ifndef CURSEDINTERFACE_H
#define CURSEDINTERFACE_H

#include "Interface.h"

class CursedInterface : public Interface{
 public:
  void start() override;
  explicit CursedInterface(Engine *engine) : Interface(engine){};
};

#endif // CURSEDINTERFACE_H
