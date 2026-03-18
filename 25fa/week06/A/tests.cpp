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
        REQUIRE(l.getSize() == 3);
        REQUIRE(l.getFirst() == 33);
        REQUIRE(l.getLast() == 55);
    }
}

TEST_CASE("toString") {
    SECTION("empty") {
    }
    SECTION("non-empty") {
        List l;
        l.prepend(55);
        l.prepend(44);
        l.prepend(33);
        l.prepend(22);
        l.prepend(11);
        // cout << l.toString() << endl;
        // output should be:
        // [11, 22, 33, 44, 55]
        ostringstream oss;
        oss << l.toString();
        REQUIRE(oss.str() == "[11, 22, 33, 44, 55]");
    }
}

TEST_CASE("operator==") {
    SECTION("empty lists") {
        List l0;
        List l1;
        REQUIRE(l0 == l1);
    }
    SECTION("empty vs non-empty") {
        List l0;
        List l1;
        l1.append(11);
        REQUIRE(!(l0 == l1));
        REQUIRE(!(l1 == l0));
    }
    SECTION("lists of different lengths") {
        List l0;
        l0.append(11);
        List l1;
        l1.prepend(22);
        l1.prepend(11);
        REQUIRE(!(l0 == l1));
        REQUIRE(!(l1 == l0));
    }
    SECTION("lists with different values") {
        List l0;
        l0.append(11);
        l0.append(22);
        l0.append(33);
        List l1;
        l1.append(11);
        l1.append(23);
        l1.append(33);
        REQUIRE(!(l0 == l1));
        REQUIRE(!(l1 == l0));
    }
}