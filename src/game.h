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
#include <vector>
#include "gamepiece.h"
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
  
  // Initialize the game
  bool initialize();
  // Runs the game loop until game is over
  void runLoop();

  // Shut down the game
  void shutdown();

 private:

  const int xWinCoordinate{100};
  const int yWinCoordinate{100};
  const int winWidth{1024};
  const int winHeight{768};
  const int flags{0};
  const int thickness{15};
  const int ballMotion{1};
  const int paddleMargin{15};
  const int paddleHeight{150};
  const int paddleMotion{1};

  const int frameMs{16}; // 60FPS = 1 frame per 16ms
  const double maxDelta{0.05};
  const double pixelsPerSecond{300.0}; // pixels per second

  bool mIsRunning; // Game should continue to run
  int mTicksCount; // for counting delta time

  Ball mBall; // Ball
  Paddle mRPaddle{winHeight}, mLPaddle{winHeight}; // Paddles
  Wall mTopWall, mBottomWall, mRightWall, mLeftWall;
  
  // Helper Functions for the game loop

  void processInput();
  void updateGame();
  void generateOutput();

  void generateGamePieces();
  void destroyGamePieces();
  
  void renderGamePieces();
  void renderGamePiece(GamePiece* g);

  SDL_Window* mWindow; // Window created by SDL 
  SDL_Renderer* mRenderer; // SDL Renderer

  struct Vector2{
    double x;
    double y;
  };

  // Vectors for positions of ball and paddles
  Vector2 mBallPos, mPaddle1Pos, mPaddle2Pos;
 
};

#endif
