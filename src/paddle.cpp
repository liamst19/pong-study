/** paddle.cpp
 *
 * Paddle object. When the ball object collides, the ball should
 * bounce back.
 * 
 */
#include "mobilepiece.h"
#include "paddle.h"

void Paddle::resetDirection(){
  direction = 0;
}

int Paddle::incrementDirection(){
  return ++direction;
}

int Paddle::decrementDirection(){
  return --direction;
}

/* function: move
 *
 * Overrides parent move() to limit movement of paddles
 * to y-axis.
 * 
 */
int Paddle::move(double seconds){
  
  yPosition += direction * yVelocity * seconds;

  return getY();
}
