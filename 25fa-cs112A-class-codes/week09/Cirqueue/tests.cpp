#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Cirqueue.h"
#include <stdexcept>

using namespace std;

TEST_CASE("Cirqueue testing"){
    Cirqueue q;
    REQUIRE(q.isEmpty() == true);
    REQUIRE_THROWS_AS(q.remove(), range_error);
    q.add(11);
    q.add(22);
    q.add(33);
    q.add(44);
    q.add(55);
    REQUIRE_THROWS_AS(q.add(666), range_error);

    REQUIRE(q.remove() == 11);
    REQUIRE(q.remove() == 22);
    REQUIRE(q.peekFirst() == 33);
    REQUIRE(q.peekLast() == 55);
    REQUIRE(q.remove() == 33);
    REQUIRE(q.remove() == 44);
    REQUIRE(q.remove() == 55);
    REQUIRE_THROWS_AS(q.remove(), range_error);

}