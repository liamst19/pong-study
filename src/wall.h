/** wall.h
 *
 * Wall object: when ball collides with the top or bottom walls, the
 * ball should bounce off. When the ball collides with the left or
 * right, a point should be given to the opposite player.
 *
 */

#ifndef WALL_H
#define WALL_H

#include "gamepiece.h"

class Wall: public GamePiece{
 public:

  Wall(){};
  ~Wall(){};
};

#endif
