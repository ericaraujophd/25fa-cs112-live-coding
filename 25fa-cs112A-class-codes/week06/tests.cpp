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
    list.append(5);
    list.append(7);
    list.append(1);

    REQUIRE(list.getSize() == 3);
}

// TEST_CASE("toString"){
    
// }

// TEST_CASE("<< operator"){
// }
