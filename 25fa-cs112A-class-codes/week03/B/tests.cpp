#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Pair.h"

TEST_CASE("Constructors") {
    SECTION("Default constructor"){
        Pair p;
        REQUIRE(p.getFirst() == 0);
        REQUIRE(p.getSecond() == 0);
    }
    SECTION("Explicit-value constructor"){
        Pair p(2, 4);
        REQUIRE(p.getFirst() == 2);
        REQUIRE(p.getSecond() == 4);

    }
}

TEST_CASE("Setters"){
    Pair p;
    p.setFirst(-5);
    p.setSecond(23);
    REQUIRE(p.getFirst() == -5);
    REQUIRE(p.getSecond() == 23);
}

TEST_CASE("to string"){
    Pair p;
    REQUIRE(p.toString() == "<0, 0>");
    p.setFirst(4);
    
    REQUIRE(p.toString() == "<4, 0>");
}

TEST_CASE("add"){
    Pair p1(1,2);
    Pair p2(3,4);
    // Pair p3 = p1 + p2;
    cout << p1 + p2;
}