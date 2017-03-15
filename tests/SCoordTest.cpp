//
// Created by imolcean on 13.03.17.
//

#include "catch.hpp"
#include "SCoord.h"

TEST_CASE("SCoord test")
{
    SECTION("Comparison")
    {
        SECTION("Equal SCoords")
        {
            SCoord v1(0, 0);
            SCoord v2(0, 0);

            REQUIRE(v1 == v2);
            REQUIRE_FALSE(v1 != v2);
        }

        SECTION("Different SCoords")
        {
            SECTION("Different X")
            {
                SCoord v1(1, 3);
                SCoord v2(6, 3);

                REQUIRE(v1 != v2);
                REQUIRE_FALSE(v1 == v2);
            }

            SECTION("Different Y")
            {
                SCoord v1(5, 0);
                SCoord v2(5, 7);

                REQUIRE(v1 != v2);
                REQUIRE_FALSE(v1 == v2);
            }

            SECTION("Different X and Y")
            {
                SCoord v1(8, 2);
                SCoord v2(3, 7);

                REQUIRE(v1 != v2);
                REQUIRE_FALSE(v1 == v2);
            }
        }
    }

    SECTION("Assignment")
    {
        SCoord v1(1, 2);
        SCoord v2 = v1;

        SCoord* pv1 = &v1;
        SCoord* pv2 = &v2;

        REQUIRE(v1 == v2);
        REQUIRE_FALSE(pv1 == pv2);
    }

    SECTION("Braces init")
    {
        SCoord v1 = {3, 5};

        SCoord r(3, 5);

        REQUIRE(v1 == r);
        REQUIRE(v1.getX() == 3);
        REQUIRE(v1.getY() == 5);
    }

    SECTION("Arithmetical operations")
    {
        SECTION("Addition")
        {
            SCoord v1(3, 4);
            SCoord v2(7, 6);

            SCoord v3 = v1 + v2;

            SCoord r(10, 10);

            REQUIRE_FALSE(v3 == v1);
            REQUIRE_FALSE(v3 == v2);
            REQUIRE(v3 == r);
        }

        SECTION("Subtraction")
        {
            SCoord v1(10, 10);
            SCoord v2(7, 6);

            SCoord v3 = v1 - v2;

            SCoord r(3, 4);

            REQUIRE_FALSE(v3 == v1);
            REQUIRE_FALSE(v3 == v2);
            REQUIRE(v3 == r);
        }
    }
}
