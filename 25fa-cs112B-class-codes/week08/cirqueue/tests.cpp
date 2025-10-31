#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Cirqueue.h"

TEST_CASE("queue"){
    Cirqueue q1;
    REQUIRE(q1.isEmpty() == true);
    q1.add(3);
    q1.add(33);
    q1.add(333);
    q1.add(3333);
    q1.add(33333);
    REQUIRE(q1.peekFirst() == 3);
    REQUIRE(q1.peekLast() == 33333);
}

