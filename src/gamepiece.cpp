/** gamepiece.cpp
 *
 * Base class for the game objects that are to be rendered.
 *
 */

#include "gamepiece.h"

int GamePiece::getWidth() {
  return width;
}

int GamePiece::getHeight() {
  return height;
}
  
// Should x and y positions specify the center or the left corner?
// I'm going to go with the center.
             
// positions of the center of the rectangle
int GamePiece::getX() {
  return xPosition;
}

int GamePiece::getY() {
  return yPosition;
}

// positions of the edges of the rectangle
int GamePiece::getXLeft()  {
  return xPosition - static_cast<int>(width/2);
}

int GamePiece::getXRight() {
  return xPosition + static_cast<int>(width/2);
}

int GamePiece::getYTop()   {
  return yPosition - static_cast<int>(height/2);
}

int GamePiece::getYBottom(){
  return yPosition + static_cast<int>(height/2);
} 

// --------------------------------------------------------------

void GamePiece::update(int width, int height, int x, int y){
  GamePiece::width = width;
  GamePiece::height = height;
  xPosition = x;
  yPosition = y;
}
  
void GamePiece::updateSize(int width, int height){
  GamePiece::width = width;
  GamePiece::height = height;
}
  
void GamePiece::updatePosition(int x, int y){
  xPosition = x;
  yPosition = y;
}
  
void GamePiece::updateXPosition(int x){
  xPosition = x;
};

void GamePiece::updateYPosition(int y){
  yPosition = y;
};
