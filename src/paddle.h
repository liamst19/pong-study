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

  void resetDirection();
  int incrementDirection();
  int decrementDirection();

  int move(double seconds);

private:
  
  int direction;
 
};

#endif
