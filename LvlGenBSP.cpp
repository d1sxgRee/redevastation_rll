#include "LvlGenBSP.h"
#include <random>

struct BspNode{
  BspNode *left = nullptr;
  BspNode *right = nullptr;
  Coords start;
  Coords end;
  constexpr static int minsize = 7;
  void split_vertical(int splitter);
  void split_horizontal(int splitter);
  void split_random(std::default_random_engine &engine);
  void dig(LvlMap *map);
  ~BspNode();
};

BspNode::~BspNode(){
  delete(left);
  delete(right);
}

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

void BspNode::split_random(std::default_random_engine &engine){
  if(end.x - start.x <= minsize || end.y - start.y <= minsize){
    return;
  }
  std::uniform_int_distribution<int> rdirection(0, 1);
  if(rdirection(engine)){
    std::uniform_int_distribution<int> rsplitter(3, (end.x - start.x) - 3);
    split_vertical(rsplitter(engine));
  }
  else{
    std::uniform_int_distribution<int> rsplitter(3, (end.y - start.y) - 3);
    split_horizontal(rsplitter(engine));
  }
  right->split_random(engine);
  left->split_random(engine);
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

  std::random_device rd;
  std::default_random_engine re(rd());
  root->split_random(re);
  
  root->dig(map);
  return map;
}
