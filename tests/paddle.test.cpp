#include <catch2/catch.hpp>
#include "../src/paddle.h"

TEST_CASE("Create paddle object"){
  Paddle paddle;

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

    SECTION("Update Position"){
      paddle.updatePosition(600, 800);
      
      REQUIRE(paddle.getX() == 600);
      REQUIRE(paddle.getY() == 800);
    }
    SECTION("Update x"){
      paddle.updateX(300);

      REQUIRE(paddle.getX() == 300);
    }

    SECTION("Update y"){
      paddle.updateY(300);

      REQUIRE(paddle.getY() == 300);
    }

    // Setting Edges
    paddle.setEdges(10, 500);

    SECTION("increment paddle"){
      paddle.resetDirection();
      paddle.updateY(50);
      paddle.incrementDirection();
      paddle.move(50);

      REQUIRE(paddle.getY() == 100);
    }

    SECTION("increment paddle, goes over the bottom edge"){
      paddle.resetDirection();
      paddle.updateY(480);
      paddle.incrementDirection();
      paddle.move(50);

      REQUIRE(paddle.getY() == 450); // edge - height
    }

    SECTION("decrement paddle"){
      paddle.resetDirection();
      paddle.updateY(150);
      paddle.decrementDirection();
      paddle.move(50);

      REQUIRE(paddle.getY() == 100);   
    }

    SECTION("decrement paddle, goes over the top edge"){
      paddle.resetDirection();
      paddle.updateY(20);
      paddle.decrementDirection();
      paddle.move(50);

      REQUIRE(paddle.getY() == 10);   
    }
  }
}
