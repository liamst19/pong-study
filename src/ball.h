/** ball.h
 *
 * Ball object.
 * 
 */

#ifndef BALL_H
#define BALL_H

#include "gamepiece.h"

class Ball: public GamePiece{
 public:
  
  Ball(){};
 ~Ball(){};

  int getX();
  int getY();
  int getWidth();
  int getHeight();

  void move(int x, int y);
};

#endif
