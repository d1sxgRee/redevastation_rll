#ifndef LVLGENBSP_H
#define LVLGENBSP_H

#include "LvlGen.h"

class LvlGenBSP: public LvlGen{
 public:
  LvlMap *generate(Coords size) override;
};

#endif // LVLGENBSP_H
