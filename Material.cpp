#include "Material.h"

Coords Material::position_get(){
  return coords;
}

void Material::move(Coords destination){
  coords.x += destination.x;
  coords.y += destination.y;
  return;
}
