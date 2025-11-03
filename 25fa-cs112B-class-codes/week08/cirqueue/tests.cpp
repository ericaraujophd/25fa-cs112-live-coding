#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Cirqueue.h"
#include <stdexcept>

using namespace std;

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
    REQUIRE_THROWS_AS(q1.add(1234), range_error);

    REQUIRE(q1.remove() == 3);
    REQUIRE(q1.remove() == 33);
    REQUIRE(q1.remove() == 333);
    REQUIRE(q1.remove() == 3333);
    REQUIRE(q1.remove() == 33333);

    REQUIRE_THROWS_AS(q1.remove(), range_error);

    q1.add(1);
    q1.add(2);
    q1.add(3);
    q1.remove();
    REQUIRE(q1.peekFirst() == 2);
    REQUIRE(q1.peekLast() == 3);
    q1.add(4);
    q1.remove();
    q1.remove();
    REQUIRE(q1.peekFirst() == 4);
    REQUIRE(q1.peekLast() == 4);

}

