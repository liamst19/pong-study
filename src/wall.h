#ifndef WALL_H
#define WALL_H

#include "gamepiece.h"

class Wall: public GamePiece{
 public:

  Wall(int x, int y, int w, int h): GamePiece(x, y, w, h) {};
  ~Wall(){};
  
  int getX();
  int getY();
  int getWidth();
  int getHeight();

};

#endif
