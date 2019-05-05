#ifndef PADDLE_H
#define PADDLE_H

#include "gamepiece.h"

class Paddle: public GamePiece{
 public:
  
  Paddle(int x, int y, int w, int h): GamePiece(x, y, w, h) {};
  ~Paddle(){};
  
  int getX();
  int getY();
  int getWidth();
  int getHeight();
 
};

#endif
