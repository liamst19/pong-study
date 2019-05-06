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

void Paddle::resetDirection(){
  direction = 0;
}

int Paddle::incrementDirection(){
  return ++direction;
}

int Paddle::decrementDirection(){
  return --direction;
}

int Paddle::move(int pixels){
  
  yPosition += direction * pixels;

  // If the paddle goes over the top or bottom edge
  if(yPosition < topEdgeY){
    yPosition = topEdgeY;
  }
  else if(yPosition + height > bottomEdgeY){
    yPosition = bottomEdgeY - height;
  }

  return yPosition;
}
