#include <catch2/catch.hpp>
#include "../src/paddle.h"

TEST_CASE("Paddle"){
  Paddle paddle;
  paddle.update(10, 50, 250, 250, 0, 10);
  paddle.setBoundary(0, 500, 0, 500);

  // Going to assume gamepiece and mobilepiece are doing their jobs
  SECTION("Move up"){
    paddle.resetDirection();
    paddle.decrementDirection();
    paddle.move(5);

    REQUIRE(paddle.getY() == 200);
  }

  SECTION("Move down"){
    paddle.resetDirection();
    paddle.incrementDirection();
    paddle.move(5);

    REQUIRE(paddle.getY() == 300);
  }
  
}
