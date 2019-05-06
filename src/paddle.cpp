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

const int Paddle::getYMin(){
  return static_cast<int>(height/2.0 + width);
}

const int Paddle::getYMax(){
  return static_cast<int>(winHeight - height/2.0 - width);
}

void Paddle::resetDirection(){
  direction = 0;
}

int Paddle::increment(){
  return ++direction;
}

int Paddle::decrement(){
  return --direction;
}

// seems kind of inelegant
int Paddle::move(double pixelsPerSecond, double deltaTime){
  
  yPosition += static_cast<int>(direction * pixelsPerSecond * deltaTime);

  if(yPosition < getYMin()){
    yPosition = getYMin();
  }
  else if(yPosition > getYMax()){
    yPosition = getYMax();
  }

  return yPosition;
}
