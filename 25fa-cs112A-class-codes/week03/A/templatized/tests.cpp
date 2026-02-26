#define CATCH_CONFIG_MAIN
#include <ostream>

#include "Pair.h"
#include "catch.hpp"

TEST_CASE("Constructors") {
    SECTION("Default constructor") {
        Pair<int> p;
        REQUIRE(p.getFirst() == 0);
        REQUIRE(p.getSecond() == 0);
    }
    SECTION("Explicit-value constructor") {
        Pair<int> p2(-5, 23);
        REQUIRE(p2.getFirst() == -5);
        REQUIRE(p2.getSecond() == 23);
    }
}

TEST_CASE("setters") {
    Pair<int> p;
    p.setFirst(5);
    p.setSecond(9);
    SECTION("setFirst") {
        REQUIRE(p.getFirst() == 5);
    }
    SECTION("setSecond") {
        REQUIRE(p.getSecond() == 9);
    }
}

TEST_CASE("toString") {
    Pair<unsigned> p(1, 2);
    REQUIRE(p.toString() == "<1, 2>");
}

TEST_CASE("<< operator") {
    Pair<short> p(2, 3);
    // cout << p << endl;
    ostringstream oss;
    oss << p;
    REQUIRE(oss.str() == "<2, 3>");
}
