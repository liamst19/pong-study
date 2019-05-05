#include <catch2/catch.hpp>
#include "../src/wall.h"

Wall wall(3, 4, 6, 0);

TEST_CASE("wall.getX() should return 3"){
  REQUIRE(wall.getX() == 3);
}

TEST_CASE("wall.getY() should return 4"){
  REQUIRE(wall.getY() == 4);
}

TEST_CASE("wall.getWidth() should return 6"){
  REQUIRE(wall.getWidth() == 6);
}

TEST_CASE("wall.getHeight() should return 0"){
  REQUIRE(wall.getHeight() == 0);
}
