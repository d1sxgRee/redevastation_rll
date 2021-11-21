#include "LvlGenBSP.h"
#include <random>

struct BspNode{
  BspNode *left = nullptr;
  BspNode *right = nullptr;
  Coords start;
  Coords end;
  static constexpr int minsize = 10;
  static constexpr int wall_offset = 5;
  void split_vertical(int splitter);
  void split_horizontal(int splitter);
  void split_random(std::default_random_engine &engine);
  void dig(LvlMap *map, std::default_random_engine &engine);
  BspNode() = default;
  ~BspNode();
  BspNode(const BspNode&) = delete;
  BspNode operator=(const BspNode&) = delete;
};

constexpr int BspNode::minsize;
constexpr int BspNode::wall_offset;

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
  if(end.x - start.x <= minsize && end.y - start.y <= minsize){
    return;
  }
  if(end.x - start.x <= minsize){
    std::uniform_int_distribution<int> rsplitter(std::max(wall_offset, (end.y - start.y) / 4),
                                                 std::min((end.y - start.y) - wall_offset, (end.y - start.y) / 4 * wall_offset));
    split_horizontal(rsplitter(engine));
    return;
  }
  if(end.y - start.y <= minsize){
    std::uniform_int_distribution<int> rsplitter(std::max(wall_offset, (end.x - start.x) / 4),
                                                 std::min((end.x - start.x) - wall_offset, (end.x - start.x) / 4 * wall_offset));
    split_vertical(rsplitter(engine));
    return;
  }
  std::uniform_int_distribution<int> rdirection(0, 1);
  if(rdirection(engine)){
    std::uniform_int_distribution<int> rsplitter(std::max(wall_offset, (end.x - start.x) / 4),
                                                 std::min((end.x - start.x) - wall_offset, (end.x - start.x) / 4 * wall_offset));
    split_vertical(rsplitter(engine));
  }
  else{
    std::uniform_int_distribution<int> rsplitter(std::max(wall_offset, (end.y - start.y) / 4),
                                                 std::min((end.y - start.y) - wall_offset, (end.y - start.y) / 4 * wall_offset));
    split_horizontal(rsplitter(engine));
  }
  right->split_random(engine);
  left->split_random(engine);
  return;
}

void BspNode::dig(LvlMap *map, std::default_random_engine &engine){
  if(left == nullptr && right == nullptr){
    std::uniform_int_distribution<int> rdigger(0, 3);
    if(rdigger(engine)){
      map->dig_rectangle({start.x + 1, start.y + 1}, {end.x - 1, end.y - 1});
    }
  }
  else{
    left->dig(map, engine);
    right->dig(map, engine);
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
  
  root->dig(map, re);
  return map;
}
