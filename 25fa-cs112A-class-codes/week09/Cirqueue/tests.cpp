#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Stack.h"

TEST_CASE("Stack testing"){
    Stack s;
    REQUIRE(s.isEmpty() == true);
    REQUIRE_THROWS_AS(s.pop(), range_error);
    s.push(7);
    s.push(8);
    REQUIRE(s.peekTop() == 8);
    s.push(9);
    REQUIRE(s.pop() == 9);
    REQUIRE(s.peekTop() == 8);
    REQUIRE(s.isEmpty() == false);
    
}