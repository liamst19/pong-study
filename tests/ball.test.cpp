#include <catch2/catch.hpp>
#include "../src/ball.h"

TEST_CASE("Ball"){
  Ball ball;
  ball.update(10, 10, 250, 250, 10, 10);
  ball.setBoundary(0, 500, 0, 500);

  SECTION("Move 1 second"){
    ball.move(1);

    REQUIRE(ball.getX() == 260);
    REQUIRE(ball.getY() == 260);
  }

  SECTION("change x-direction"){
    ball.updateXPosition(450);
    ball.updateVelocity(10, 0);
    ball.changeXDirection();

    REQUIRE(ball.getXVelocity() == -10.0);
  }

  SECTION("change y-direction"){
    ball.updateYPosition(50);
    ball.updateVelocity(0, 10);
    ball.changeYDirection();

    REQUIRE(ball.getYVelocity() == -10.0);
  }
}
