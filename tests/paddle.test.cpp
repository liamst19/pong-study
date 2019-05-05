#include <catch2/catch.hpp>
#include "../src/paddle.h"

Paddle paddle(3, 4, 6, 0);

TEST_CASE("paddle.getX() should return 3"){
  REQUIRE(paddle.getX() == 3);
}

TEST_CASE("paddle.getY() should return 4"){
  REQUIRE(paddle.getY() == 4);
}

TEST_CASE("paddle.getWidth() should return 6"){
  REQUIRE(paddle.getWidth() == 6);
}

TEST_CASE("paddle.getHeight() should return 0"){
  REQUIRE(paddle.getHeight() == 0);
}
