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
#include <cstdlib>
#include "game.h"
#include "gamepiece.h"
#include "mobilepiece.h"
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

    
  // Update Paddle Positions
  // Left Paddle
  mLPaddle.resetDirection();
  if(state[SDL_SCANCODE_W]){
    mLPaddle.decrementDirection();
  }
  if(state[SDL_SCANCODE_S]){
    mLPaddle.incrementDirection();
  }
  // Right Paddle
  mRPaddle.resetDirection();
  if(state[SDL_SCANCODE_K]){
    mRPaddle.decrementDirection();
  }
  if(state[SDL_SCANCODE_J]){
    mRPaddle.incrementDirection();
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

  //clamp maximum delta time value
  if(deltaTime > maxDelta){
    deltaTime = maxDelta;
  }

  mTicksCount = SDL_GetTicks(); // update tick counts for next frame

  // move paddles
  mLPaddle.move(deltaTime);
  mRPaddle.move(deltaTime);
  
  // check paddle for wall hits here?
  
  // move ball
  mBall.move(deltaTime);

  // Check for ball collisions here, since collisions are events
  // that are external to objects.
  
  // Flip y-direction if ball collides or exceeds
  // top or bottom edges.
  if((mBall.getYTop() <= topBoundaryY && mBall.getYVelocity() < 0.0)
  || (mBall.getYBottom() >= bottomBoundaryY && mBall.getYVelocity() > 0.0)){
    mBall.changeYDirection();
  }

  // When ball hits the side walls
  if(mBall.isAtLeft()){
    mBall.updatePosition(winWidth/2, winHeight/2);
    mBall.changeXDirection();
  }
  else if(mBall.isAtRight()){
    mBall.updatePosition(winWidth/2, winHeight/2);
    mBall.changeXDirection();
  }

  // Flip x-direction if ball collides with paddle.
  double diff{0};

  // Left Paddle Collision
  diff = std::abs(mBall.getY() - mLPaddle.getY());
  if(diff <= mLPaddle.getHeight()/2.0
     && mLPaddle.isRectColliding(mBall.getXLeft(), mBall.getXRight(),
                                 mBall.getYTop(), mBall.getYBottom())
     && mBall.getXVelocity() < 0){
       mBall.changeXDirection(); 
     }

  // Right Paddle Collision
  diff = std::abs(mBall.getY() - mRPaddle.getY());
  if(diff <= mRPaddle.getHeight()/2.0
     && mRPaddle.isRectColliding(mBall.getXLeft(), mBall.getXRight(),
                                 mBall.getYTop(), mBall.getYBottom())
     && mBall.getXVelocity() > 0){
       mBall.changeXDirection(); 
     }
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
  
   mBall.update(ballSize,
                ballSize,
                winWidth/2,
                winHeight/2,
                ballXVelocity,
                ballYVelocity);
   mBall.setBoundary(topBoundaryY, bottomBoundaryY, leftBoundaryX, rightBoundaryX);
   
   mLPaddle.update(paddleThickness,
                   paddleHeight,
                   wallThickness + paddleMargin,
                   winHeight/2,
                   paddleXVelocity,
                   paddleYVelocity);
   
   mLPaddle.setBoundary(topBoundaryY, bottomBoundaryY, leftBoundaryX, rightBoundaryX);
   
   mRPaddle.update(paddleThickness,
                   paddleHeight,
                   winWidth - wallThickness - paddleMargin,
                   winHeight/2,
                   paddleXVelocity,
                   paddleYVelocity);
   
   mRPaddle.setBoundary(topBoundaryY, bottomBoundaryY, leftBoundaryX, rightBoundaryX);
   
   // Walls
   mTopWall.update(winWidth,
                   wallThickness,
                   winWidth/2,
                   wallThickness/2);
   
   mBottomWall.update(winWidth,
                      wallThickness,
                      winWidth/2,
                      winHeight - wallThickness/2);
   
   mRightWall.update(wallThickness,
                     winHeight,
                     winWidth - wallThickness/2,
                     winHeight/2);
   
   mLeftWall.update(wallThickness,
                    winHeight,
                    wallThickness/2,
                    winHeight/2);

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
  SDL_Rect rect{g->getXLeft(),
                g->getYTop(),
                g->getWidth(),
                g->getHeight()};
  SDL_RenderFillRect(mRenderer, &rect);
}
