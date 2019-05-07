/** mobilepiece.h
 *
 * mobile gamepiece object, with velocity and move() method
 * 
 */

#ifndef MOBILEPIECE_H
#define MOBILEPIECE_H

#include "gamepiece.h"

class MobilePiece: public GamePiece{
  
 public:

  MobilePiece(){};
  virtual ~MobilePiece(){};

  void move(double seconds);

  double getXVelocity();
  double getYVelocity();

  void update(int w, int h, int x, int y, double xVel, double yVel);
  void updateVelocity(double xVel, double yVel);
  void updateXVelocity(double xVel);
  void updateYVelocity(double yVel);
  void changeXDirection();
  void changeYDirection();
  
  bool isPointColliding(int x, int y);
  bool isColliding(GamePiece piece);
  
 protected:

  double xVelocity{0}, yVelocity{0}; // for motion
};

#endif
