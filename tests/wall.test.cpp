#include <catch2/catch.hpp>
#include "../src/wall.h"

TEST_CASE("Create wall object"){
  Wall wall;

  REQUIRE(wall.getX() == 0);
  REQUIRE(wall.getY() == 0);
  REQUIRE(wall.getWidth() == 0);
  REQUIRE(wall.getHeight() == 0);

  SECTION("Update wall"){
    wall.update(100, 100, 50, 50);

    REQUIRE(wall.getX() == 100);
    REQUIRE(wall.getY() == 100);
    REQUIRE(wall.getWidth() == 50);
    REQUIRE(wall.getHeight() == 50);
  }

  SECTION("Update Position"){
    wall.updatePosition(600, 800);
    
    REQUIRE(wall.getX() == 600);
    REQUIRE(wall.getY() == 800);
  }
  
  SECTION("Update x"){
    wall.updateX(300);
    
    REQUIRE(wall.getX() == 300);
  }
  
  SECTION("Update y"){
    wall.updateY(300);

    REQUIRE(wall.getY() == 300);
  }
}
