/** paddle.cpp
 *
 * Paddle object. When the ball object collides, the ball should
 * bounce back.
 * 
 */

#include "gamepiece.h"
#include "paddle.h"

int Paddle::getX(){
  return xPosition;
}

int Paddle::getY(){
  return yPosition;
}

int Paddle::getWidth(){
  return width;
}

int Paddle::getHeight(){
  return height;
}
