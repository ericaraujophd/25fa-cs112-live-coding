#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "List.h"

TEST_CASE("Constructors") {
    SECTION("Default constructor"){
        List list;
        REQUIRE(list.getSize() == 0);
    }
}

TEST_CASE("append"){
    List list;
    list.append(4);
    list.append(14);
    list.append(24);
    list.append(34);

    REQUIRE(list.getSize() == 4);
    REQUIRE(list.getFirst() == 4);
    REQUIRE(list.getLast() == 34);
}

TEST_CASE("prepend"){
    List list;
    list.prepend(4);
    list.prepend(14);
    list.prepend(24);
    list.prepend(34);

    REQUIRE(list.getSize() == 4);
    REQUIRE(list.getFirst() == 34);
    REQUIRE(list.getLast() == 4);
}

