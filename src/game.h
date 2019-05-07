/** game.h
 *
 * Entry point for the game.
 *
 * TODO: try to see if I can meaningfully separate out output
 * processes, so that it may be possible, if need arises, to use
 * libraries other than SDL.
 * 
 */
  
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "gamepiece.h"
#include "mobilepiece.h"
#include "ball.h"
#include "paddle.h"
#include "wall.h"

/* Main interface to initialize, run, and shut down the game.
 *
 */
class Game{

 public:
  Game():
    mIsRunning(true),
    mTicksCount(0)
  {};
  ~Game(){};
  
  bool initialize(); // Initialize the game
  void runLoop(); // Runs the game loop until game is over
  void shutdown(); // Shut down the game

 private:

  // --------------------------------------------------
  // Some initial game settings
  const int xWinCoordinate{100};
  const int yWinCoordinate{100};
  const int winWidth{1024};
  const int winHeight{768};
  const int sdlFlags{0};
  
  const int ballSize{10};
  const int ballMotion{1};
  
  const int wallThickness{15};
  
  const int paddleThickness{15};
  const int paddleMargin{25};
  const int paddleHeight{150};
  const int paddleMotion{1};

  const int frameMs{16}; // 60FPS = 1 frame per 16ms
  const double maxDelta{0.05};

  // Game Boundaries
  const int topBoundaryY{wallThickness};
  const int bottomBoundaryY{winHeight - wallThickness};
  const int leftBoundaryX{wallThickness};
  const int rightBoundaryX{winWidth - wallThickness};

  // Initial Velocities
  const double paddleXVelocity{0.0};
  const double paddleYVelocity{300.0};
  const double ballXVelocity{-200.0};
  const double ballYVelocity{235.0};
  // --------------------------------------------------

  bool mIsRunning; // Game should continue to run
  int mTicksCount; // for counting delta time

  Ball mBall; // Ball
  Paddle mRPaddle, mLPaddle; // Paddles
  Wall mTopWall, mBottomWall, mRightWall, mLeftWall; // walls

  SDL_Window* mWindow; // Window created by SDL 
  SDL_Renderer* mRenderer; // SDL Renderer
  
  // Helper Functions for the game loop ---------------

  void processInput();
  void updateGame();
  void generateOutput();

  void moveGamePieces(double deltaTime);
  void movePaddle(Paddle* paddle, double deltaTime);
  void moveBall(Ball* ball, double deltaTime);

  void generateGamePieces();
  void destroyGamePieces();
  
  void renderGamePieces();
  void renderGamePiece(GamePiece* g);
};

#endif
