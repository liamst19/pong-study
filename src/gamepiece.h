/** gamepiece.h
 *
 * Base class for the game objects that are to be rendered.
 *
 */

#ifndef GAMEPIECE_H
#define GAMEPIECE_H

class GamePiece{

public:

  GamePiece():
    xPosition(0),
    yPosition(0),
    width(0),
    height(0)
  { };

  virtual ~GamePiece(){};
              
  virtual int getX() { return xPosition; };
  virtual int getY() { return yPosition; };
  virtual int getWidth() { return width; };
  virtual int getHeight() { return height; };

  void update(int x, int y, int w, int h){
    xPosition = x;
    yPosition = y;
    width = w;
    height = h;
  };
  void updatePosition(int x, int y){
    xPosition = x;
    yPosition = y;
  };
  void updateX(int x){ xPosition = x; };
  void updateY(int y){ yPosition = y; };

protected:

  int xPosition, yPosition;
  int width, height;
  
};

#endif
