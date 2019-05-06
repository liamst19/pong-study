#include <catch2/catch.hpp>
#include "../src/ball.h"

TEST_CASE("Create ball object"){
  Ball ball;

  REQUIRE(ball.getX() == 0);
  REQUIRE(ball.getY() == 0);
  REQUIRE(ball.getWidth() == 0);
  REQUIRE(ball.getHeight() == 0);

  SECTION("Update ball"){
    ball.update(100, 100, 50, 50);

    REQUIRE(ball.getX() == 75);
    REQUIRE(ball.getY() == 75);
    REQUIRE(ball.getWidth() == 50);
    REQUIRE(ball.getHeight() == 50);
    
    SECTION("Update Position"){
      ball.updatePosition(600, 800);

      REQUIRE(ball.getX() == 575);
      REQUIRE(ball.getY() == 775);
    }
  
    SECTION("Update x"){
      ball.updateX(300);

      REQUIRE(ball.getX() == 275);
    }

    SECTION("Update y"){
      ball.updateY(300);

      REQUIRE(ball.getY() == 275);
    }

  }
}
