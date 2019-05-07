/** gamepiece.h
 *
 * Base class for the game objects that are to be rendered.
 *
 */

#ifndef GAMEPIECE_H
#define GAMEPIECE_H

class GamePiece{

public:

  GamePiece(){};
  virtual ~GamePiece(){};

  int getWidth();
  int getHeight();
  int getX();
  int getY();
  int getXLeft();
  int getXRight();
  int getYTop();
  int getYBottom();  

  void update(int w, int h, int x, int y);
  void updateSize(int w, int h);
  void updatePosition(int x, int y);
  void updateXPosition(int x);
  void updateYPosition(int y);

protected:

  int width{0}, height{0};
  int xPosition{0}, yPosition{0};
  
};

#endif
