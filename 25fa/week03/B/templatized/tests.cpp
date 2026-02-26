#define CATCH_CONFIG_MAIN
#include "Pair.h"
#include "catch.hpp"

TEST_CASE("Constructors") {
    SECTION("Default constructor") {
        Pair<int> p;
        REQUIRE(p.getFirst() == 0);
        REQUIRE(p.getSecond() == 0);
    }
    SECTION("Explicit-value constructor") {
        Pair<short> p2(-5, 23);
        REQUIRE(p2.getFirst() == -5);
        REQUIRE(p2.getSecond() == 23);
    }
}

TEST_CASE("setters") {
    Pair<unsigned> p;
    p.setFirst(5);
    p.setSecond(9);
    SECTION("setFirst") {
        REQUIRE(p.getFirst() == 5);
    }
    SECTION("setSecond") {
        REQUIRE(p.getSecond() == 9);
    }
    Pair<string> pstr("hi", "hello");
}

TEST_CASE("toString") {
    Pair<int> p(1, 2);
    REQUIRE(p.toString() == "<1, 2>");
}

TEST_CASE("<< operator") {
    Pair<long> p(2, 3);
    cout << p << endl;
    // User needs to verify that "<2, 3>" came out on the console.
}
