/** game.cpp
 *
 * Entry point for the game.
 *
 * TODO: try to see if I can meaningfully separate out output
 * processes, so that it may be possible, if need arises, to use
 * libraries other than SDL.
 * 
 */

#include <SDL2/SDL.h>
#include "game.h"
#include "gamepiece.h"
#include "wall.h"
#include "ball.h"
#include "paddle.h"

// PUBLIC

bool Game::initialize(){
  
  int sdlResult = SDL_Init(SDL_INIT_VIDEO);
  if(sdlResult != 0){
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return false;
  };

  // create window
 mWindow = SDL_CreateWindow("Pong Study",
                             xWinCoordinate,
                             yWinCoordinate,
                             winWidth,
                             winHeight,
                             flags);
  if(!mWindow){
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  };

  // create renderer
  mRenderer = SDL_CreateRenderer(
         mWindow,
         -1,
         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );
  
  return true;
}

void Game::runLoop(){
  while(mIsRunning){
    processInput();
    updateGame();
    generateOutput();
  };
}

void Game::shutdown(){
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}

// PRIVATE

void Game::processInput(){
  SDL_Event event;
  
  while(SDL_PollEvent(&event)){
    switch(event.type){
    case SDL_QUIT:
      mIsRunning = false;
      break;
    };
  };

  // Get state of keyboard
  const Uint8* state = SDL_GetKeyboardState(NULL);
  if(state[SDL_SCANCODE_ESCAPE]){
    mIsRunning = false;
  };
}

void Game::updateGame(){

  double deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0;
  mTicksCount = SDL_GetTicks();
  
}

void Game::generateOutput(){

  SDL_SetRenderDrawColor(mRenderer,
                         0,
                         0,
                         255,
                         255);
  SDL_RenderClear(mRenderer);

  SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
  
  renderWalls();
  renderBall();
  renderPaddles();
 
  SDL_RenderPresent(mRenderer);
}

void Game::renderWalls(){
  
  Wall top(0,
           0,
           winWidth,
           thickness);
  Wall bottom(0,
              winHeight - thickness,
              winWidth,
              thickness);
  Wall right(winWidth - thickness,
             0,
             thickness,
             winHeight);
  Wall left(0,
            0,
            thickness,
            winHeight);

  renderGamePiece(&top);
  renderGamePiece(&bottom);
  renderGamePiece(&right);
  renderGamePiece(&left);
}

void Game::renderBall(){

  Ball ball(winWidth/2,
            winHeight/2,
            thickness,
            thickness);
  renderGamePiece(&ball);
}

void Game::renderPaddles(){

  Paddle leftPaddle(thickness*2,
                    static_cast<int>((winHeight-paddleHeight)/2),
                    thickness,
                    paddleHeight);
  Paddle rightPaddle(winWidth - thickness*3,
                     static_cast<int>((winHeight-paddleHeight)/2),
                     thickness,
                     paddleHeight);

  renderGamePiece(&leftPaddle);
  renderGamePiece(&rightPaddle);
}

void Game::renderGamePiece(GamePiece* g){
  SDL_Rect rect{g->getX(),
                g->getY(),
                g->getWidth(),
                g->getHeight()};
  SDL_RenderFillRect(mRenderer, &rect);
}
