/** mobilepiece.cpp
 *
 *  mobile game piece
 *  
 */

#include "gamepiece.h"
#include "mobilepiece.h"

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

void MobilePiece::changeXDirection(){
  xVelocity *= -1;
}

void MobilePiece::changeYDirection(){
  yVelocity *= -1;
}

// --------------------------------------------------

/* function: isPointColliding
 *
 * checks whether the coordinate is within the bounds of
 * game object
 *
 */
bool MobilePiece::isPointColliding(int x, int y){
  return (y >= getYTop())
      && (y <= getYBottom())
      && (x >= getXLeft())
      && (x <= getXRight());
}

/* function: isColliding()
 *
 * checks whether given rectangle is colliding with object
 *
 */
bool MobilePiece::isColliding(GamePiece piece){  
  
  // This seems to work, but I wonder if there are better ways to do this,
  // perhaps informing which side piece is colliding.
  // I would at least like to find more informative name than vert and horz.
  bool vert1 = ((piece.getYTop() <= getYTop()) && (piece.getYBottom() >= getYBottom()))
            || ((piece.getYTop() >= getYTop()) && (piece.getYBottom() <= getYBottom()));
  bool vert2 = ((piece.getYTop() >= getYTop() && piece.getYTop() <= getYBottom()))
            || ((piece.getYBottom() >= getYTop()) && (piece.getYBottom() <= getYBottom()));

  bool horz1 = ((piece.getXLeft() <= getXLeft()) && (piece.getXRight() >= getXRight()))
            || ((piece.getXLeft() >= getXLeft()) && (piece.getXRight() <= getXRight()));
  bool horz2 = ((piece.getXLeft() >= getXLeft()) && (piece.getXLeft() <= getXRight()))
            || ((piece.getXRight() >= getXLeft()) && (piece.getXRight() <= getXRight()));
  
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
