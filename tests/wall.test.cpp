#include <catch2/catch.hpp>
#include "../src/wall.h"

TEST_CASE("Wall"){
  Wall wall;

  SECTION("Initialize"){
    REQUIRE(wall.getWidth() == 0);
    REQUIRE(wall.getHeight() == 0);

    REQUIRE(wall.getX() == 0);
    REQUIRE(wall.getY() == 0);
    REQUIRE(wall.getXLeft() == 0);
    REQUIRE(wall.getXRight() == 0);
    REQUIRE(wall.getYTop() == 0);
    REQUIRE(wall.getYBottom() == 0);

    SECTION("Update Wall"){
      wall.update(25,    // width
                       50,    // height
                       100,   // x position (center)
                       250);  // y position (center)
   
      REQUIRE(wall.getWidth() == 25);
      REQUIRE(wall.getHeight() == 50);
    
      REQUIRE(wall.getX() == 100);
      REQUIRE(wall.getY() == 250);
      REQUIRE(wall.getXLeft() == static_cast<int>(100-(25/2)));
      REQUIRE(wall.getXRight() == static_cast<int>(100+(25/2)));
      REQUIRE(wall.getYTop() == static_cast<int>(250-(50/2)));
      REQUIRE(wall.getYBottom() == static_cast<int>(250+(50/2)));
    
      SECTION("Update Size"){
        wall.updateSize(80,    // width
                             10);   // height
    
        REQUIRE(wall.getWidth() == 80);
        REQUIRE(wall.getHeight() == 10);
    
        REQUIRE(wall.getX() == 100);
        REQUIRE(wall.getY() == 250);
        REQUIRE(wall.getXLeft() == static_cast<int>(100-(80/2)));
        REQUIRE(wall.getXRight() == static_cast<int>(100+(80/2)));
        REQUIRE(wall.getYTop() == static_cast<int>(250-(10/2)));
        REQUIRE(wall.getYBottom() == static_cast<int>(250+(10/2)));
      }
      
      SECTION("Update Position"){
        wall.updatePosition(80,    // x-position
                                 10);   // y-position
    
        REQUIRE(wall.getWidth() == 25);
        REQUIRE(wall.getHeight() == 50);
    
        REQUIRE(wall.getX() == 80);
        REQUIRE(wall.getY() == 10);
        REQUIRE(wall.getXLeft() == static_cast<int>(80-(25/2)));
        REQUIRE(wall.getXRight() == static_cast<int>(80+(25/2)));
        REQUIRE(wall.getYTop() == static_cast<int>(10-(50/2)));
        REQUIRE(wall.getYBottom() == static_cast<int>(10+(50/2)));
      }
      
      SECTION("Update x Position"){
        wall.updateXPosition(85);   // x-position
        
        REQUIRE(wall.getWidth() == 25);
        REQUIRE(wall.getHeight() == 50);
    
        REQUIRE(wall.getX() == 85);
        REQUIRE(wall.getY() == 250);
        REQUIRE(wall.getXLeft() == static_cast<int>(85-(25/2)));
        REQUIRE(wall.getXRight() == static_cast<int>(85+(25/2)));
        REQUIRE(wall.getYTop() == static_cast<int>(250-(50/2)));
        REQUIRE(wall.getYBottom() == static_cast<int>(250+(50/2)));
      }
      
      SECTION("Update y Position"){
        wall.updateYPosition(88);   // y-position
        
        REQUIRE(wall.getWidth() == 25);
        REQUIRE(wall.getHeight() == 50);
    
        REQUIRE(wall.getX() == 100);
        REQUIRE(wall.getY() == 88);
        REQUIRE(wall.getXLeft() == static_cast<int>(100-(25/2)));
        REQUIRE(wall.getXRight() == static_cast<int>(100+(25/2)));
        REQUIRE(wall.getYTop() == static_cast<int>(88-(50/2)));
        REQUIRE(wall.getYBottom() == static_cast<int>(88+(50/2)));
      }
    }
  }
}
