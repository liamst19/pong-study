/** paddle.h
 *
 * Paddle object. When the ball object collides, the ball should
 * bounce back.
 * 
 */

#ifndef PADDLE_H
#define PADDLE_H

#include "mobilepiece.h"

class Paddle: public MobilePiece{
  
 public:
  
  Paddle():
    direction(0){};
  ~Paddle(){};

  int incrementDirection();
  int decrementDirection();
  void resetDirection();
  int move(double seconds);

private:
  
  int ballEdge; // left = -1, right = 1
  int direction;
  int topEdgeY, bottomEdgeY;
 
};

#endif
