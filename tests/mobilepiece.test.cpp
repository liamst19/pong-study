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
    
      SECTION("Update Size"){
        mobilePiece.updateSize(80,    // width
                             10);   // height
    
        REQUIRE(mobilePiece.getWidth() == 80);
        REQUIRE(mobilePiece.getHeight() == 10);
    
        REQUIRE(mobilePiece.getX() == 100);
        REQUIRE(mobilePiece.getY() == 250);
        REQUIRE(mobilePiece.getXLeft() == static_cast<int>(100-(80/2)));
        REQUIRE(mobilePiece.getXRight() == static_cast<int>(100+(80/2)));
        REQUIRE(mobilePiece.getYTop() == static_cast<int>(250-(10/2)));
        REQUIRE(mobilePiece.getYBottom() == static_cast<int>(250+(10/2)));
    
        REQUIRE(mobilePiece.getXVelocity() == 45.0);
        REQUIRE(mobilePiece.getYVelocity() == 35.0);
      }
      
      SECTION("Update Position"){
        mobilePiece.updatePosition(80,    // x-position
                                 10);   // y-position
    
        REQUIRE(mobilePiece.getWidth() == 25);
        REQUIRE(mobilePiece.getHeight() == 50);
    
        REQUIRE(mobilePiece.getX() == 80);
        REQUIRE(mobilePiece.getY() == 10);
        REQUIRE(mobilePiece.getXLeft() == static_cast<int>(80-(25/2)));
        REQUIRE(mobilePiece.getXRight() == static_cast<int>(80+(25/2)));
        REQUIRE(mobilePiece.getYTop() == static_cast<int>(10-(50/2)));
        REQUIRE(mobilePiece.getYBottom() == static_cast<int>(10+(50/2)));
    
        REQUIRE(mobilePiece.getXVelocity() == 45.0);
        REQUIRE(mobilePiece.getYVelocity() == 35.0);
      }
      
      SECTION("Update x Position"){
        mobilePiece.updateXPosition(85);   // x-position
        
        REQUIRE(mobilePiece.getWidth() == 25);
        REQUIRE(mobilePiece.getHeight() == 50);
    
        REQUIRE(mobilePiece.getX() == 85);
        REQUIRE(mobilePiece.getY() == 250);
        REQUIRE(mobilePiece.getXLeft() == static_cast<int>(85-(25/2)));
        REQUIRE(mobilePiece.getXRight() == static_cast<int>(85+(25/2)));
        REQUIRE(mobilePiece.getYTop() == static_cast<int>(250-(50/2)));
        REQUIRE(mobilePiece.getYBottom() == static_cast<int>(250+(50/2)));
    
        REQUIRE(mobilePiece.getXVelocity() == 45.0);
        REQUIRE(mobilePiece.getYVelocity() == 35.0);
      }
      
      SECTION("Update y Position"){
        mobilePiece.updateYPosition(88);   // y-position
        
        REQUIRE(mobilePiece.getWidth() == 25);
        REQUIRE(mobilePiece.getHeight() == 50);
    
        REQUIRE(mobilePiece.getX() == 100);
        REQUIRE(mobilePiece.getY() == 88);
        REQUIRE(mobilePiece.getXLeft() == static_cast<int>(100-(25/2)));
        REQUIRE(mobilePiece.getXRight() == static_cast<int>(100+(25/2)));
        REQUIRE(mobilePiece.getYTop() == static_cast<int>(88-(50/2)));
        REQUIRE(mobilePiece.getYBottom() == static_cast<int>(88+(50/2)));
    
        REQUIRE(mobilePiece.getXVelocity() == 45.0);
        REQUIRE(mobilePiece.getYVelocity() == 35.0);
      }
      
      SECTION("Update Velocity"){
        mobilePiece.updateVelocity(80.5,    // x-velocity
                                 10.3);   // y-velocity
        
        REQUIRE(mobilePiece.getWidth() == 25);
        REQUIRE(mobilePiece.getHeight() == 50);
    
        REQUIRE(mobilePiece.getX() == 100);
        REQUIRE(mobilePiece.getY() == 250);
        REQUIRE(mobilePiece.getXLeft() == static_cast<int>(100-(25/2)));
        REQUIRE(mobilePiece.getXRight() == static_cast<int>(100+(25/2)));
        REQUIRE(mobilePiece.getYTop() == static_cast<int>(250-(50/2)));
        REQUIRE(mobilePiece.getYBottom() == static_cast<int>(250+(50/2)));
    
        REQUIRE(mobilePiece.getXVelocity() == 80.5);
        REQUIRE(mobilePiece.getYVelocity() == 10.3);    
      }
      
      SECTION("Update x Velocity"){
        mobilePiece.updateXVelocity(80);   // x-velocity
        
        REQUIRE(mobilePiece.getWidth() == 25);
        REQUIRE(mobilePiece.getHeight() == 50);
    
        REQUIRE(mobilePiece.getX() == 100);
        REQUIRE(mobilePiece.getY() == 250);
        REQUIRE(mobilePiece.getXLeft() == static_cast<int>(100-(25/2)));
        REQUIRE(mobilePiece.getXRight() == static_cast<int>(100+(25/2)));
        REQUIRE(mobilePiece.getYTop() == static_cast<int>(250-(50/2)));
        REQUIRE(mobilePiece.getYBottom() == static_cast<int>(250+(50/2)));
    
        REQUIRE(mobilePiece.getXVelocity() == 80.0);
        REQUIRE(mobilePiece.getYVelocity() == 35.0);    
      }
      
      SECTION("Update y Velocity"){
        mobilePiece.updateYVelocity(80);   // y-velocity
        
        REQUIRE(mobilePiece.getWidth() == 25);
        REQUIRE(mobilePiece.getHeight() == 50);
    
        REQUIRE(mobilePiece.getX() == 100);
        REQUIRE(mobilePiece.getY() == 250);
        REQUIRE(mobilePiece.getXLeft() == static_cast<int>(100-(25/2)));
        REQUIRE(mobilePiece.getXRight() == static_cast<int>(100+(25/2)));
        REQUIRE(mobilePiece.getYTop() == static_cast<int>(250-(50/2)));
        REQUIRE(mobilePiece.getYBottom() == static_cast<int>(250+(50/2)));
    
        REQUIRE(mobilePiece.getXVelocity() == 45.0);
        REQUIRE(mobilePiece.getYVelocity() == 80.0);    
      }
    }
  }

  SECTION("Boundary Test"){
    mobilePiece.update(10, 10, 50, 50, 0, 0);
    mobilePiece.setBoundary(0, 100, 0, 100);

    REQUIRE_FALSE(mobilePiece.isAtBottom());
    REQUIRE_FALSE(mobilePiece.isAtTop());
    REQUIRE_FALSE(mobilePiece.isAtLeft());
    REQUIRE_FALSE(mobilePiece.isAtRight());

    SECTION("Hitting Top"){
      mobilePiece.updateYPosition(0);
      REQUIRE(mobilePiece.isAtTop());
    }
    
    SECTION("Hitting Bottom"){
      mobilePiece.updateYPosition(100);
      REQUIRE(mobilePiece.isAtBottom());
    }
    
    SECTION("Hitting Left"){
      mobilePiece.updateXPosition(0);
      REQUIRE(mobilePiece.isAtLeft());
    }
    
    SECTION("Hitting Right"){
      mobilePiece.updateXPosition(100);
      REQUIRE(mobilePiece.isAtRight());
    }
  }

  SECTION("Collision Test"){
    mobilePiece.update(10, 10, 50, 50, 0, 0);
 
    SECTION("Collision"){
      REQUIRE(mobilePiece.isColliding(48, 55));
      REQUIRE_FALSE(mobilePiece.isColliding(6, 6));
    }

    SECTION("Overlapping object"){
      REQUIRE(mobilePiece.isRectColliding(45, 55, 45, 50));
    }
    
    SECTION("Corners touching"){
      REQUIRE(mobilePiece.isRectColliding(35, 45, 35, 45)); // top left corner
      REQUIRE(mobilePiece.isRectColliding(55, 65, 35, 45)); // top right corner
      REQUIRE(mobilePiece.isRectColliding(35, 45, 55, 65)); // bottom left corner
      REQUIRE(mobilePiece.isRectColliding(55, 65, 55, 65)); // bottom right corner
    }

    SECTION("Sides Overlapping"){
      REQUIRE(mobilePiece.isRectColliding(53, 56, 52, 54)); // obj inside
      REQUIRE(mobilePiece.isRectColliding(20, 100, 10, 85)); // obj envelopes
      REQUIRE(mobilePiece.isRectColliding(35, 65, 50, 65)); // top side
      REQUIRE(mobilePiece.isRectColliding(35, 65, 65, 50)); // top side (swapped)
      REQUIRE(mobilePiece.isRectColliding(35, 65, 35, 50)); // bottom side
      REQUIRE(mobilePiece.isRectColliding(50, 65, 35, 65)); // left side
      REQUIRE(mobilePiece.isRectColliding(35, 50, 35, 65)); // right side
    }

    SECTION("Object not touching or overlapping"){
      REQUIRE_FALSE(mobilePiece.isRectColliding(10, 15, 10, 15));
      REQUIRE_FALSE(mobilePiece.isRectColliding(10, 15, 50, 75));
      REQUIRE_FALSE(mobilePiece.isRectColliding(50, 65, 10, 15));
      REQUIRE_FALSE(mobilePiece.isRectColliding(100, 150, 10, 15));
    }
       
  }
}
