#define CATCH_CONFIG_MAIN
#include <iostream>

#include "List.h"
#include "catch.hpp"
using namespace std;

TEST_CASE("default constructor") {
    List scores;
    REQUIRE(scores.getSize() == 0);
}

TEST_CASE("prepend") {
    SECTION("empty list") {
        List l;
        l.prepend(55);
        REQUIRE(l.getSize() == 1);
        REQUIRE(l.getFirst() == 55);
        REQUIRE(l.getLast() == 55);
    }

    SECTION("non-empty list") {
        List l;
        l.prepend(55);
        l.prepend(44);
        REQUIRE(l.getSize() == 2);
        REQUIRE(l.getFirst() == 44);
        REQUIRE(l.getLast() == 55);
        l.prepend(33);
        l.prepend(22);
        l.prepend(11);
        REQUIRE(l.getSize() == 5);
        REQUIRE(l.getFirst() == 11);
        REQUIRE(l.getLast() == 55);
    }
}

TEST_CASE("toString") {
    SECTION("empty list") {
        // List l;
        // l.prepend(55);
        // REQUIRE(l.getSize() == 1);
        // REQUIRE(l.getFirst() == 55);
        // REQUIRE(l.getLast() == 55);
    }

    SECTION("non-empty list") {
        List l;
        l.prepend(55);
        l.prepend(44);
        l.prepend(33);
        l.prepend(22);
        l.prepend(11);
        REQUIRE(l.getSize() == 5);
        REQUIRE(l.getFirst() == 11);
        REQUIRE(l.getLast() == 55);
        cout << l.toString() << endl;
        // 11 22 33 44 55
    }
}
