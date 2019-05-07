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

int Paddle::move(double seconds){
  
  yPosition += direction * yVelocity * seconds;

  // If the paddle goes over the top or bottom edge
  if(isAtTop()){
    updateYPosition(static_cast<int>(boundaryTopY + (height/2)));
  }
  else if(isAtBottom()){
    updateYPosition(static_cast<int>(boundaryBottomY - (height/2)));
  }

  return getY();
}
