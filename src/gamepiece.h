#ifndef GAMEPIECE_H
#define GAMEPIECE_H

class GamePiece{

 public:

  GamePiece(int x, int y, int w, int h):
    xPosition(x),
    yPosition(y),
    width(w),
    height(h)
  { };

  virtual ~GamePiece(){};
              
  virtual int getX() { return xPosition; };
  virtual int getY() { return yPosition; };
  virtual int getWidth() { return width; };
  virtual int getHeight() { return height; };

  int xPosition, yPosition;
  int width, height;
  
};

#endif
