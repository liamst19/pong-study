#include <catch2/catch.hpp>
#include "../src/ball.h"

Ball ball(3, 4, 6, 0);

TEST_CASE("ball.getX() should return 0"){
  REQUIRE(ball.getX() == 0);
}

TEST_CASE("ball.getY() should return 1"){
  REQUIRE(ball.getY() == 1);
}

TEST_CASE("ball.getWidth() should return 6"){
  REQUIRE(ball.getWidth() == 6);
}

TEST_CASE("ball.getHeight() should return 0"){
  REQUIRE(ball.getHeight() == 0);
}
