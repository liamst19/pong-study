#include <catch2/catch.hpp>
#include "../src/gamepiece.h"

TEST_CASE("GamePiece"){
  GamePiece gamePiece;

  SECTION("Initialize"){
    REQUIRE(gamePiece.getWidth() == 0);
    REQUIRE(gamePiece.getHeight() == 0);

    REQUIRE(gamePiece.getX() == 0);
    REQUIRE(gamePiece.getY() == 0);
    REQUIRE(gamePiece.getXLeft() == 0);
    REQUIRE(gamePiece.getXRight() == 0);
    REQUIRE(gamePiece.getYTop() == 0);
    REQUIRE(gamePiece.getYBottom() == 0);

    SECTION("Update GamePiece"){
      gamePiece.update(25,    // width
                       50,    // height
                       100,   // x position (center)
                       250);  // y position (center)
   
      REQUIRE(gamePiece.getWidth() == 25);
      REQUIRE(gamePiece.getHeight() == 50);
    
      REQUIRE(gamePiece.getX() == 100);
      REQUIRE(gamePiece.getY() == 250);
      REQUIRE(gamePiece.getXLeft() == static_cast<int>(100-(25/2)));
      REQUIRE(gamePiece.getXRight() == static_cast<int>(100+(25/2)));
      REQUIRE(gamePiece.getYTop() == static_cast<int>(250-(50/2)));
      REQUIRE(gamePiece.getYBottom() == static_cast<int>(250+(50/2)));
    
      SECTION("Update Size"){
        gamePiece.updateSize(80,    // width
                             10);   // height
    
        REQUIRE(gamePiece.getWidth() == 80);
        REQUIRE(gamePiece.getHeight() == 10);
    
        REQUIRE(gamePiece.getX() == 100);
        REQUIRE(gamePiece.getY() == 250);
        REQUIRE(gamePiece.getXLeft() == static_cast<int>(100-(80/2)));
        REQUIRE(gamePiece.getXRight() == static_cast<int>(100+(80/2)));
        REQUIRE(gamePiece.getYTop() == static_cast<int>(250-(10/2)));
        REQUIRE(gamePiece.getYBottom() == static_cast<int>(250+(10/2)));
      }
      
      SECTION("Update Position"){
        gamePiece.updatePosition(80,    // x-position
                                 10);   // y-position
    
        REQUIRE(gamePiece.getWidth() == 25);
        REQUIRE(gamePiece.getHeight() == 50);
    
        REQUIRE(gamePiece.getX() == 80);
        REQUIRE(gamePiece.getY() == 10);
        REQUIRE(gamePiece.getXLeft() == static_cast<int>(80-(25/2)));
        REQUIRE(gamePiece.getXRight() == static_cast<int>(80+(25/2)));
        REQUIRE(gamePiece.getYTop() == static_cast<int>(10-(50/2)));
        REQUIRE(gamePiece.getYBottom() == static_cast<int>(10+(50/2)));
      }
      
      SECTION("Update x Position"){
        gamePiece.updateXPosition(85);   // x-position
        
        REQUIRE(gamePiece.getWidth() == 25);
        REQUIRE(gamePiece.getHeight() == 50);
    
        REQUIRE(gamePiece.getX() == 85);
        REQUIRE(gamePiece.getY() == 250);
        REQUIRE(gamePiece.getXLeft() == static_cast<int>(85-(25/2)));
        REQUIRE(gamePiece.getXRight() == static_cast<int>(85+(25/2)));
        REQUIRE(gamePiece.getYTop() == static_cast<int>(250-(50/2)));
        REQUIRE(gamePiece.getYBottom() == static_cast<int>(250+(50/2)));
      }
      
      SECTION("Update y Position"){
        gamePiece.updateYPosition(88);   // y-position
        
        REQUIRE(gamePiece.getWidth() == 25);
        REQUIRE(gamePiece.getHeight() == 50);
    
        REQUIRE(gamePiece.getX() == 100);
        REQUIRE(gamePiece.getY() == 88);
        REQUIRE(gamePiece.getXLeft() == static_cast<int>(100-(25/2)));
        REQUIRE(gamePiece.getXRight() == static_cast<int>(100+(25/2)));
        REQUIRE(gamePiece.getYTop() == static_cast<int>(88-(50/2)));
        REQUIRE(gamePiece.getYBottom() == static_cast<int>(88+(50/2)));
      }
    }
  }
}
