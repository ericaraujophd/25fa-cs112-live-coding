#define CATCH_CONFIG_MAIN
#include "List.h"
#include "catch.hpp"

TEST_CASE("default constructor") {
    List scores;
    REQUIRE(scores.getSize() == 0);
}

TEST_CASE("prepend") {
    SECTION("empty list") {
        List l;
        l.prepend(55);
        REQUIRE(l.getSize() == 1);
        // REQUIRE(l.getFirst() == 55);
        // REQUIRE(l.getLast() == 55);
    }

    SECTION("non-empty list") {
        List l;
        l.prepend(55);
        l.prepend(44);
        REQUIRE(l.getSize() == 2);
        // MORE Here.
    }
}
