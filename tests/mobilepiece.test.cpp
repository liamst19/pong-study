#include <catch2/catch.hpp>
#include "../src/mobilepiece.h"

TEST_CASE("MobilePiece"){
  MobilePiece mobilePiece;
  REQUIRE(mobilePiece.getWidth() == 0);
  REQUIRE(mobilePiece.getHeight() == 0);
  
  REQUIRE(mobilePiece.getX() == 0);
  REQUIRE(mobilePiece.getY() == 0);
  REQUIRE(mobilePiece.getXLeft() == 0);
  REQUIRE(mobilePiece.getXRight() == 0);
  REQUIRE(mobilePiece.getYTop() == 0);
  REQUIRE(mobilePiece.getYBottom() == 0);
  
  REQUIRE(mobilePiece.getXVelocity() == 0.0);
  REQUIRE(mobilePiece.getYVelocity() == 0.0);
 
  SECTION("Initialize"){

    SECTION("Update GamePiece"){
      mobilePiece.update(25,    // width
                       50,    // height
                       100,   // x position (center)
                       250,   // y position (center)
                       45.0,  // x velocity
                       35.0); // y velocity
    
      REQUIRE(mobilePiece.getWidth() == 25);
      REQUIRE(mobilePiece.getHeight() == 50);
    
      REQUIRE(mobilePiece.getX() == 100);
      REQUIRE(mobilePiece.getY() == 250);
      REQUIRE(mobilePiece.getXLeft() == static_cast<int>(100-(25/2)));
      REQUIRE(mobilePiece.getXRight() == static_cast<int>(100+(25/2)));
      REQUIRE(mobilePiece.getYTop() == static_cast<int>(250-(50/2)));
      REQUIRE(mobilePiece.getYBottom() == static_cast<int>(250+(50/2)));
    
      REQUIRE(mobilePiece.getXVelocity() == 45.0);
      REQUIRE(mobilePiece.getYVelocity() == 35.0);
      
      SECTION("Update Velocity"){
        mobilePiece.updateVelocity(80.5,    // x-velocity
                                 10.3);   // y-velocity
    
        REQUIRE(mobilePiece.getXVelocity() == 80.5);
        REQUIRE(mobilePiece.getYVelocity() == 10.3);    
      }
      
      SECTION("Update x Velocity"){
        mobilePiece.updateXVelocity(80);   // x-velocity
    
        REQUIRE(mobilePiece.getXVelocity() == 80.0);
        REQUIRE(mobilePiece.getYVelocity() == 35.0);    
      }
      
      SECTION("Update y Velocity"){
        mobilePiece.updateYVelocity(80);   // y-velocity
    
        REQUIRE(mobilePiece.getXVelocity() == 45.0);
        REQUIRE(mobilePiece.getYVelocity() == 80.0);    
      }
    }
  }

  SECTION("Motion Test"){
    mobilePiece.update(10, 10, 250, 250, 10, 10);

    SECTION("Move 1 second"){
      mobilePiece.move(1);

      REQUIRE(mobilePiece.getX() == 260);
      REQUIRE(mobilePiece.getY() == 260);
    }

    SECTION("change x-direction"){
      mobilePiece.updateXPosition(450);
      mobilePiece.updateVelocity(10, 0);
      mobilePiece.changeXDirection();

      REQUIRE(mobilePiece.getXVelocity() == -10.0);
    }

    SECTION("change y-direction"){
      mobilePiece.updateYPosition(50);
      mobilePiece.updateVelocity(0, 10);
      mobilePiece.changeYDirection();

      REQUIRE(mobilePiece.getYVelocity() == -10.0);
    }
  }

  SECTION("Collision Test"){
    mobilePiece.update(10, 10, 50, 50, 0, 0);
 
    SECTION("Collision"){
      REQUIRE(mobilePiece.isPointColliding(48, 55));
      REQUIRE_FALSE(mobilePiece.isPointColliding(6, 6));
    }

    GamePiece gPiece;
    gPiece.update(10, 10, 50, 50);
    
    SECTION("Object corners touching"){
      gPiece.updatePosition(45, 45);
      REQUIRE(mobilePiece.isColliding(gPiece));
      gPiece.updatePosition(45, 55);
      REQUIRE(mobilePiece.isColliding(gPiece));
      gPiece.updatePosition(55, 45);
      REQUIRE(mobilePiece.isColliding(gPiece));
      gPiece.updatePosition(55, 55);
      REQUIRE(mobilePiece.isColliding(gPiece));
    }

    SECTION("Objects overlapping"){
      gPiece.update(10, 10, 50, 50);
      REQUIRE(mobilePiece.isColliding(gPiece));
      gPiece.update(10, 10, 55, 55);
      REQUIRE(mobilePiece.isColliding(gPiece));
      gPiece.update(30, 30, 50, 50);      
      REQUIRE(mobilePiece.isColliding(gPiece));
      gPiece.update(2, 2, 50, 50);      
      REQUIRE(mobilePiece.isColliding(gPiece));
      gPiece.update(30, 2, 50, 50);      
      REQUIRE(mobilePiece.isColliding(gPiece));
      gPiece.update(2, 30, 50, 50);      
      REQUIRE(mobilePiece.isColliding(gPiece));
    }

    SECTION("Object not touching or overlapping"){
      gPiece.update(10, 10, 5, 5);      
      REQUIRE_FALSE(mobilePiece.isColliding(gPiece));
      gPiece.update(10, 10, 75, 75);      
      REQUIRE_FALSE(mobilePiece.isColliding(gPiece));
    }
       
  }
}
