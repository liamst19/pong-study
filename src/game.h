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
#include "ball.h"
#include "paddle.h"

/* Main interface to initialize, run, and shut down the game.
 *
 */
class Game{
 public:
  Game(): mIsRunning(true) {};
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
  const int paddleMargin{15};
  const int paddleHeight{150};
  
  // Helper Functions for the game loop
  void processInput();
  void updateGame();
  void generateOutput();

  // Rendering
  void renderWalls();
  void renderBall();
  void renderPaddles();
  void renderGamePiece(GamePiece* g);

  // Window created by SDL 
  SDL_Window* mWindow;
  // SDL Renderer
  SDL_Renderer* mRenderer;

  // Game should continue to run
  bool mIsRunning;

  int mTicksCount;
  
  struct Vector2{
    double x;
    double y;
  };

  // Vectors for positions of ball and paddles
  Vector2 mBallPos, mPaddle1Pos, mPaddle2Pos;
  
 
};

#endif
