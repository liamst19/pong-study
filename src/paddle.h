/** paddle.h
 *
 * Paddle object. When the ball object collides, the ball should
 * bounce back.
 * 
 */

#ifndef PADDLE_H
#define PADDLE_H

#include "gamepiece.h"

class Paddle: public GamePiece{
 public:
  Paddle():
    direction(0){};
  ~Paddle(){};

  void setEdges(int top, int bottom){
    topEdgeY = top;
    bottomEdgeY = bottom;
  }
  
  int getX();
  int getY();
  int getWidth();
  int getHeight();

  int incrementDirection();
  int decrementDirection();
  void resetDirection();
  int move(int pixels);

private:
  int direction;
  int topEdgeY, bottomEdgeY;
 
};

#endif
