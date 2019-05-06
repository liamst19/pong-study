#include <catch2/catch.hpp>
#include "../src/paddle.h"

TEST_CASE("Create paddle object"){
  Paddle paddle{765};

  REQUIRE(paddle.getX() == 0);
  REQUIRE(paddle.getY() == 0);
  REQUIRE(paddle.getWidth() == 0);
  REQUIRE(paddle.getHeight() == 0);

  SECTION("Update paddle"){
    paddle.update(100, 100, 50, 50);

    REQUIRE(paddle.getX() == 100);
    REQUIRE(paddle.getY() == 100);
    REQUIRE(paddle.getWidth() == 50);
    REQUIRE(paddle.getHeight() == 50);
  }

  SECTION("Update Position"){
    paddle.updatePosition(600, 800);
      
    REQUIRE(paddle.getX() == 600);
    REQUIRE(paddle.getY() == 800);
  
    SECTION("Update x"){
      paddle.updateX(300);

      REQUIRE(paddle.getX() == 300);
    }

    SECTION("Update y"){
      paddle.updateY(300);

      REQUIRE(paddle.getY() == 300);
    }

    SECTION("increment paddle"){
      paddle.updateY(150);
      paddle.increment();
      paddle.move(5, 10);

      REQUIRE(paddle.getY() == 200);
    }

    SECTION("decrement paddle"){
      paddle.resetDirection();
      paddle.updateY(150);
      paddle.decrement();
      paddle.move(5, 10);

      REQUIRE(paddle.getY() == 100);   
    }
  }
}
