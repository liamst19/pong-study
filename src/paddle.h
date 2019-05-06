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
  Paddle(int h): winHeight(h), direction{0}{};
  ~Paddle(){};
  
  int getX();
  int getY();
  int getWidth();
  int getHeight();

  int increment();
  int decrement();
  void resetDirection();
  int move(double pixelsPerSecond, double deltaTime);
  
  const int getYMin();
  const int getYMax();

private:
  int winHeight;
  int direction;
 
};

#endif
