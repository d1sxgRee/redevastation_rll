#include "LvlGenBSP.h"

struct BspNode{
  BspNode *left = nullptr;
  BspNode *right = nullptr;
  Coords start;
  Coords end;
  void split_vertical(int splitter);
  void split_horizontal(int splitter);
  void dig(LvlMap *map);
};

void BspNode::split_vertical(int splitter){
  left = new BspNode;
  right = new BspNode;
  left->start = start;
  left->end = {start.x + splitter - 1, end.y};
  right->start = {start.x + splitter + 1, start.y};
  right->end = end;
  return;
}

void BspNode::split_horizontal(int splitter){
  left = new BspNode;
  right = new BspNode;
  left->start = start;
  left->end = {end.x, start.y + splitter - 1};
  right->start = {start.x, start.y + splitter + 1};
  right->end = end;
  return;
}

void BspNode::dig(LvlMap *map){
  if(left == nullptr && right == nullptr){
    map->dig_rectangle(start, end);
  }
  else{
    left->dig(map);
    right->dig(map);
    map->dig_rectangle({
        (left->start.x + left->end.x) / 2,
        (left->start.y + left->end.y) / 2}, {
        (right->start.x + right->end.x) / 2,
        (right->start.y + right->end.y) / 2});
  }
  return;
}

LvlMap *LvlGenBSP::generate(Coords size){
  LvlMap *map = new LvlMap(size);
  for(int y = 0; y < size.y; y++){
    for(int x = 0; x < size.x; x++){
      Coords c = {x, y};
      map->cell_set(c, 1);
    }
  }
  BspNode *root = new BspNode;
  root->start = {1, 1};
  root->end = {size.x - 2, size.x - 2};
  root->split_vertical(50);
  root->left->split_horizontal(76);
  root->left->right->split_vertical(25);
  root->right->split_horizontal(60);
  root->dig(map);
  return map;
}
