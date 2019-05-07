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
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}

// PRIVATE --------------------------------------------------

/* function: processInput()
 *
 * Get keyboard input and do something with it
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

  // Exit Game
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

  moveGamePieces(deltaTime); // Do stuff with game pieces
  
}

/* function: moveGamePieces()
 *
 *
 */
void Game::moveGamePieces(double deltaTime){

  // move paddles
  movePaddle(&mLPaddle, deltaTime);
  movePaddle(&mRPaddle, deltaTime);
  
  // move ball
  moveBall(&mBall, deltaTime);

}

/* function: movePaddle()
 *
 *
 */
void Game::movePaddle(Paddle* paddle, double deltaTime){

  // move paddles
  paddle->move(deltaTime);
  
  // check paddle for wall hits here?
  if(paddle->isColliding(mTopWall)){
    paddle->updateYPosition(topBoundaryY + paddle->getHeight()/2);
  }
  else if(paddle->isColliding(mBottomWall)){
    paddle->updateYPosition(bottomBoundaryY - paddle->getHeight()/2);
  }
  
}

/* function: moveBall()
 *
 *
 */
void Game::moveBall(Ball* ball, double deltaTime){

  ball->move(deltaTime);
  
  // Flip y-direction if ball collides or exceeds top or bottom
  if((ball->getYTop() <= topBoundaryY && ball->getYVelocity() < 0.0)
  || (ball->getYBottom() >= bottomBoundaryY && ball->getYVelocity() > 0.0)){
    ball->changeYDirection();
  }

  // When ball hits the side walls
  bool goal = false;

  // In case there will be scoring
  if(ball->getXLeft() < leftBoundaryX){
    SDL_Log("Right player scores");
    goal = true;
  }
  else if(ball->getXRight() > rightBoundaryX){
    SDL_Log("Left player scores");
    goal = true;
  }

  if(goal){
    ball->updatePosition(winWidth/2, winHeight/2);
    ball->changeXDirection();
  }

  // Flip x-direction if ball collides with paddle.
  // TODO?: pass a predicate to a function?
  double diff{0};

  // Left Paddle Collision
  diff = std::abs(ball->getY() - mLPaddle.getY());
  if(diff <= mLPaddle.getHeight()/2.0
     && mLPaddle.isColliding(*ball)
     && ball->getXVelocity() < 0){
       ball->changeXDirection(); 
     }

  // Right Paddle Collision
  diff = std::abs(ball->getY() - mRPaddle.getY());
  if(diff <= mRPaddle.getHeight()/2.0
     && mRPaddle.isColliding(*ball)
     && ball->getXVelocity() > 0){
       ball->changeXDirection(); 
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
