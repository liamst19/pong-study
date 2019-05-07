#include <catch2/catch.hpp>
#include "../src/paddle.h"

TEST_CASE("Paddle"){
  Paddle paddle;
  paddle.update(10, 50, 250, 250, 10, 10);

  // Going to assume gamepiece and mobilepiece are doing their jobs
  SECTION("Move up"){
    paddle.resetDirection();
    paddle.decrementDirection();
    paddle.move(5);

    REQUIRE(paddle.getY() == 200);
    REQUIRE(paddle.getX() == 250);
  }

  SECTION("Move down"){
    paddle.resetDirection();
    paddle.incrementDirection();
    paddle.move(5);

    REQUIRE(paddle.getY() == 300);
    REQUIRE(paddle.getX() == 250);
  }
  
}
