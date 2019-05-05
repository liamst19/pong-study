#ifndef BALL_H
#define BALL_H

#include "gamepiece.h"

class Ball: public GamePiece{
 public:
  
 Ball(int x, int y, int w, int h): GamePiece(x, y, w, h) {};
 ~Ball(){};
  
 int getX();
 int getY();
 int getWidth();
 int getHeight();
};

#endif
