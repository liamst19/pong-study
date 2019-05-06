/** game.cpp
 *
 * Entry point for the game.
 *
 * TODO: try to see if I can meaningfully separate out output
 * processes, so that it may be possible, if need arises, to use
 * libraries other than SDL.
 * 
 */

#include <vector>
#include <SDL2/SDL.h>
#include "game.h"
#include "gamepiece.h"
#include "wall.h"
#include "ball.h"
#include "paddle.h"

// PUBLIC -----------------------------------------------------

/*
 *
 *
 */
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

  // Initialize Game Pieces
  generateGamePieces();
  
  return true;
}

/*
 *
 *
 */
void Game::runLoop(){
  while(mIsRunning){
    processInput();
    updateGame();
    generateOutput();
  };
}

/*
 *
 *
 */
void Game::shutdown(){

  // destroy objects
  
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}

// PRIVATE --------------------------------------------------

/*
 *
 *
 */
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

    
  // Update Paddle Position
  mLPaddle.resetDirection();
  if(state[SDL_SCANCODE_W]){
    mLPaddle.decrement();
  }
  
  if(state[SDL_SCANCODE_S]){
    mLPaddle.increment();
  }

}

/* function: updateGame()
 *
 * Update objects in game world as function of delta time
 */
void Game::updateGame(){
  
  // Wait until given time span (frameMs) has elapsed since last frame
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + frameMs)){};

  // SDL_GetTicks() returns the number of milliseconds elapsed
  // since SDL_Init() call. Delta time is the difference in ticks
  // from last frame, converted to seconds.
  double deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0;

  mTicksCount = SDL_GetTicks(); // update tick counts for next frame
  
  //clamp maximum delta time value
  if(deltaTime > maxDelta){
    deltaTime = maxDelta;
  }

  mLPaddle.move(pixelsPerSecond, deltaTime);

}

/*
 *
 *
 */
void Game::generateOutput(){

  SDL_SetRenderDrawColor(mRenderer,
                         0,
                         0,
                         255,
                         255);
  SDL_RenderClear(mRenderer);

  SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
  
  renderGamePieces();
 
  SDL_RenderPresent(mRenderer);
}


/* function: generateGamePieces()
 *
 *
 */
void Game::generateGamePieces(){
  SDL_Log("Generating Game Pieces");
  
   mBall.update(winWidth/2,
                winHeight/2,
                thickness,
                thickness);
   mRPaddle.update(winWidth - thickness*3,
                     static_cast<int>((winHeight-paddleHeight)/2),
                     thickness,
                     paddleHeight);
   mLPaddle.update(thickness*2,
                    static_cast<int>((winHeight-paddleHeight)/2),
                    thickness,
                    paddleHeight);
   
   // Walls
   mTopWall.update(0,
                   0,
                   winWidth,
                   thickness);
   mBottomWall.update(0,
                      winHeight - thickness,
                      winWidth,
                      thickness);
   mRightWall.update(winWidth - thickness,
                     0,
                     thickness,
                     winHeight);
   mLeftWall.update(0,
                    0,
                    thickness,
                    winHeight);

}

/* function: renderGamePieces()
 *
 *
 */
void Game::renderGamePieces(){
  renderGamePiece(&mBall);
  renderGamePiece(&mRPaddle);
  renderGamePiece(&mLPaddle);
  renderGamePiece(&mTopWall);
  renderGamePiece(&mBottomWall);
  renderGamePiece(&mLeftWall);
  renderGamePiece(&mRightWall);
}

/* function: destroyGamePieces()
 *
 *
 */
void Game::destroyGamePieces(){
}

/*
 *
 *
 */
void Game::renderGamePiece(GamePiece* g){
  SDL_Rect rect{g->getX(),
                g->getY(),
                g->getWidth(),
                g->getHeight()};
  SDL_RenderFillRect(mRenderer, &rect);
}
