//
// Created by imolcean on 16.03.17.
//

#include "catch.hpp"
#include "Snake.h"

TEST_CASE("Snake test")
{
    SCoord start = {10, 10};
    Snake snake(start, SDirection::LEFT);

    SECTION("Constructor")
    {
        REQUIRE(snake.getHead() == start);
        REQUIRE(snake.getDirection() == SDirection::LEFT);
        REQUIRE_FALSE(snake.into());
        REQUIRE(snake.size() == 3);
    }

    SECTION("Set direction")
    {
        SECTION("Valid")
        {
            snake.setDirection(SDirection::UP);

            REQUIRE(snake.getDirection() == SDirection::UP);
        }

        SECTION("Invalid")
        {
            snake.setDirection(SDirection::RIGHT);

            REQUIRE(snake.getDirection() == SDirection::LEFT);
        }
    }

    SECTION("Moving")
    {
        SCoord pos;

        SECTION("No growth")
        {
            snake.move();

            pos = {9, 10};

            REQUIRE(snake.size() == 3);
            REQUIRE(snake.getGrowth() == 0);
            REQUIRE(snake.getHead() == pos);
        }

        SECTION("Growth")
        {
            SECTION("One bit")
            {
                snake.grow();
                snake.move();

                pos = {9, 10};

                REQUIRE(snake.size() == 4);
                REQUIRE(snake.getGrowth() == 0);
                REQUIRE(snake.getHead() == pos);
            }

            SECTION("Three bits")
            {
                snake.grow(3);
                snake.move();
                snake.move();
                snake.move();

                pos = {7, 10};

                REQUIRE(snake.size() == 6);
                REQUIRE(snake.getGrowth() == 0);
                REQUIRE(snake.getHead() == pos);
            }
        }
    }
}