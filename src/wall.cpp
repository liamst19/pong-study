/** wall.cpp
 *
 * Wall object: when ball collides with the top or bottom walls, the
 * ball should bounce off. When the ball collides with the left or
 * right, a point should be given to the opposite player.
 *
 */

#include "gamepiece.h"
#include "wall.h"

int Wall::getX(){
  return xPosition; 
}

int Wall::getY(){
  return yPosition;
}

int Wall::getWidth(){
  return width;
}

int Wall::getHeight(){
  return height;
}
