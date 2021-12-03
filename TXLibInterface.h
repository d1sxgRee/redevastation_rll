#ifndef TXLIBINTERFACE_H
#define TXLIBINTERFACE_H

#include "Interface.h"

class TXLibInterface : public Interface{
 public:
  void start() override;
  explicit TXLibInterface(Engine *engine) : Interface(engine){};
};

#endif // TXLIBINTERFACE_H
