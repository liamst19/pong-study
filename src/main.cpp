/** main.cpp
 *
 *  
 */

#include <iostream>
#include<SDL2/SDL.h>

#include "game.h"

int main(int argc, char* argv[]){

  SDL_Log("Starting");
  
  Game game;
  if(game.initialize()){
    game.runLoop();
  }
  game.shutdown();
  
  return 0;
}
