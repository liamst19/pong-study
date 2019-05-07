/** mobilepiece.cpp
 *
 *  mobile game piece
 *  
 */

#include "gamepiece.h"
#include "mobilepiece.h"

/* function: setBoundary()
 *
 * Sets the bounds beyond which pieces can't move past. 
 */
void MobilePiece::setBoundary(int yTop, int yBottom, int xLeft, int xRight){
  boundaryTopY = yTop;
  boundaryBottomY = yBottom;
  boundaryLeftX = xLeft;
  boundaryRightX = xRight;
}

// velocities of the object in motion
double MobilePiece::getXVelocity() {
  return xVelocity;
}

double MobilePiece::getYVelocity() {
  return yVelocity;
}

// --------------------------------------------------

void MobilePiece::update(int width, int height, int x, int y, double xVel, double yVel){
  GamePiece::update(width, height, x, y);
  xVelocity = xVel;
  yVelocity = yVel;
}
  
void MobilePiece::updateVelocity(double xVel, double yVel){
  xVelocity = xVel;
  yVelocity = yVel;
}

void MobilePiece::updateXVelocity(double xVel){
  xVelocity = xVel;
}

void MobilePiece::updateYVelocity(double yVel){
  yVelocity = yVel;
}

// --------------------------------------------------
// Functions to check position

bool MobilePiece::isAtTop(){
  return getYTop() <= boundaryTopY;
}

bool MobilePiece::isAtBottom(){
  return getYBottom() >= boundaryBottomY;
}

bool MobilePiece::isAtLeft(){
  return getXLeft() <= boundaryLeftX;
}

bool MobilePiece::isAtRight(){
  return getXRight() >= boundaryRightX;
}

/* function: isColliding
 *
 * checks whether the coordinate is within the bounds of
 * game object
 *
 */
bool MobilePiece::isColliding(int x, int y){
  return (y >= getYTop())
      && (y <= getYBottom())
      && (x >= getXLeft())
      && (x <= getXRight());
}

/* function: isRectColliding()
 *
 * checks whether given rectangle is colliding with object
 *
 */
bool MobilePiece::isRectColliding(int xLeft, int xRight, int yTop, int yBottom){  

  // Swap if necessary
  int swap{0};
  if(xLeft > xRight){
    swap = xLeft;
    xLeft = xRight;
    xRight = swap;
  }
  if(yTop > yBottom){
    swap = yTop;
    yTop = yBottom;
    yBottom = swap;
  }
  
  bool vert1 = ((yTop <= getYTop()) && (yBottom >= getYBottom()))
            || ((yTop >= getYTop()) && (yBottom <= getYBottom()));
  bool vert2 = ((yTop >= getYTop() && yTop <= getYBottom()))
            || ((yBottom >= getYTop()) && (yBottom <= getYBottom()));

  bool horz1 = ((xLeft <= getXLeft()) && (xRight >= getXRight()))
            || ((xLeft >= getXLeft()) && (xRight <= getXRight()));
  bool horz2 = ((xLeft >= getXLeft()) && (xLeft <= getXRight()))
            || ((xRight >= getXLeft()) && (xRight <= getXRight()));
  
  return (vert1 || vert2) && (horz1 || horz2);
}

// --------------------------------------------------

/* function: move()
 *
 * Moves the piece by velocity * seconds
 * 
 */
void MobilePiece::move(double seconds){
  xPosition += static_cast<int>(xVelocity * seconds);
  yPosition += static_cast<int>(yVelocity * seconds);
}

void MobilePiece::changeXDirection(){
  xVelocity *= -1;
}

void MobilePiece::changeYDirection(){
  yVelocity *= -1;
}
