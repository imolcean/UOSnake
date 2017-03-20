//
// Created by imolcean on 20.03.17.
//

#include <SCell.h>
#include "catch.hpp"

TEST_CASE("SCell test")
{
    SECTION("Items")
    {
        SECTION("Place on empty cell")
        {
            SCell t;

            REQUIRE(t.placeItem(SItem::Type::APPLE));
            REQUIRE(t.getItem()->getType() == SItem::Type::APPLE);
        }

        SECTION("Place on wall")
        {
            SCell t(true);

            REQUIRE_FALSE(t.placeItem(SItem::Type::APPLE));
            REQUIRE(t.getItem() == nullptr);
        }

        SECTION("Place on another item")
        {
            SCell t;
            t.placeItem(SItem::Type::APPLE);

            REQUIRE_FALSE(t.placeItem(SItem::Type::CHERRY));
            REQUIRE(t.getItem()->getType() == SItem::Type::APPLE);
        }

        SECTION("Removing from an empty cell")
        {
            SCell t;
            t.removeItem();

            REQUIRE_FALSE(t.placeItem(SItem::Type::APPLE));
            REQUIRE(t.empty());
            REQUIRE(t.getItem() == nullptr);
        }

        SECTION("Remove and place another one")
        {
            SCell t;
            t.placeItem(SItem::Type::APPLE);
            t.removeItem();

            REQUIRE(t.placeItem(SItem::Type::CHERRY));
            REQUIRE(t.getItem()->getType() == SItem::Type::CHERRY);
        }
    }

    SECTION("Copy constructor")
    {
        SECTION("No wall and no item")
        {
            SCell a;
            SCell t(a);

            REQUIRE_FALSE(&a == &t);

            REQUIRE_FALSE(t.isWall());
            REQUIRE(t.empty());
            REQUIRE(t.getItem() == nullptr);
        }

        SECTION("Wall but no item")
        {
            SCell a(true);
            SCell t(a);

            REQUIRE_FALSE(&a == &t);

            REQUIRE(t.isWall());
            REQUIRE(t.empty());
            REQUIRE(t.getItem() == nullptr);
        }

        SECTION("No wall and an item")
        {
            SCell a;
            a.placeItem(SItem::Type::APPLE);

            SCell t(a);

            REQUIRE_FALSE(&a == &t);

            REQUIRE_FALSE(t.isWall());
            REQUIRE_FALSE(t.empty());
            REQUIRE_FALSE(t.getItem() == nullptr);
            REQUIRE(t.getItem() == a.getItem());
        }
    }

    SECTION("Swap")
    {
        SECTION("Free cells")
        {
            SCell a;
            SCell b;

            swap(a, b);

            REQUIRE(a.empty());
            REQUIRE_FALSE(a.isWall());

            REQUIRE(b.empty());
            REQUIRE_FALSE(b.isWall());
        }

        SECTION("One ell is a wall")
        {
            SCell a(true);
            SCell b;

            swap(a, b);

            REQUIRE(a.empty());
            REQUIRE_FALSE(a.isWall());

            REQUIRE(b.empty());
            REQUIRE(b.isWall());
        }

        SECTION("One cell with an item")
        {
            SCell a;
            SCell b;

            a.placeItem(SItem::Type::APPLE);

            swap(a, b);

            REQUIRE(a.empty());
            REQUIRE_FALSE(a.isWall());

            REQUIRE_FALSE(b.empty());
            REQUIRE(b.getItem()->getType() == SItem::Type::APPLE);
            REQUIRE_FALSE(b.isWall());
        }

        SECTION("Both cells with items")
        {
            SCell a;
            SCell b;

            a.placeItem(SItem::Type::APPLE);
            b.placeItem(SItem::Type::CHERRY);

            swap(a, b);

            REQUIRE_FALSE(a.empty());
            REQUIRE(a.getItem()->getType() == SItem::Type::CHERRY);
            REQUIRE_FALSE(a.isWall());

            REQUIRE_FALSE(b.empty());
            REQUIRE(b.getItem()->getType() == SItem::Type::APPLE);
            REQUIRE_FALSE(b.isWall());
        }
    }

    SECTION("Assignment operator")
    {
        SECTION("Assignment to a wall")
        {
            SCell a(true);
            SCell t = a;

            REQUIRE_FALSE(&a == &t);

            REQUIRE(t.isWall());
            REQUIRE(t.empty());
        }

        SECTION("Assignment to a cell with an item")
        {
            SCell a;
            a.placeItem(SItem::Type::APPLE);

            SCell t = a;

            REQUIRE_FALSE(&a == &t);

            REQUIRE_FALSE(t.isWall());
            REQUIRE_FALSE(t.empty());
            REQUIRE(t.getItem()->getType() == SItem::Type::APPLE);
            REQUIRE_FALSE(a.getItem() == t.getItem());
        }
    }
}