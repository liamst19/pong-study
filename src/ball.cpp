/** ball.cpp
 *
 * Ball object.
 * 
 */

#include "gamepiece.h"
#include "ball.h"

int Ball::getX(){
  return static_cast<int>(xPosition - width/2);
}

int Ball::getY(){
  return static_cast<int>(yPosition - width/2); 
}

int Ball::getWidth(){
  return width;
}

int Ball::getHeight(){
  return height;
}

void Ball::move(int x, int y){
  xPosition += x;
  yPosition += y;
}
