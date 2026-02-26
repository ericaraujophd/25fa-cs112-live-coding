#define CATCH_CONFIG_MAIN
#include "PyList.h"
#include "catch.hpp"

TEST_CASE("constructors") {
    SECTION("default constructor") {
        PyList p;
        REQUIRE(p.getSize() == 0);
        REQUIRE(p.getCapacity() == 0);
    }
}

TEST_CASE("append") {
    SECTION("to empty list") {
        PyList p;
        p.append(11);
        REQUIRE(p.getSize() == 1);
        REQUIRE(p.getCapacity() == 1);
        REQUIRE(p.getItem(0) == 11);
    }
    SECTION("to list with 1 item") {
        PyList p;
        p.append(11);
        p.append(22);
        REQUIRE(p.getSize() == 2);
        REQUIRE(p.getCapacity() == 2);
        REQUIRE(p.getItem(0) == 11);
        REQUIRE(p.getItem(1) == 22);
    }
    SECTION("lots of items") {
        PyList p;
        for (int i = 0; i < 1000; i++) {
            p.append(i * 11);
            REQUIRE(p.getSize() == i + 1);
            REQUIRE(p.getItem(i) == i * 11);
        }
        REQUIRE(p.getCapacity() == 1024);
    }
}

TEST_CASE("getItem") {
    PyList p2;
    p2.append(11);
    REQUIRE(p2.getItem(0) == 11);
    REQUIRE_THROWS_AS(p2.getItem(-1), invalid_argument);
    REQUIRE_THROWS_AS(p2.getItem(1), invalid_argument);
}

TEST_CASE("setItem") {
    PyList p3;
    p3.append(11);
    REQUIRE(p3.getItem(0) == 11);
    p3.setItem(0, 77);
    REQUIRE(p3.getItem(0) == 77);
    REQUIRE(p3.getSize() == 1);

    REQUIRE_THROWS_AS(p3.setItem(-1, 44), invalid_argument);
}

TEST_CASE("injection operator") {
    PyList p;
    p.append(11);
    p.append(22);
    p.append(33);
    p.append(44);
    // Want to see 11 22 33 44
    ostringstream oss;
    oss << p;
    REQUIRE(oss.str() == "11 22 33 44 ");
}

TEST_CASE("indexing operator") {
    SECTION("empty losit") {
    }
    SECTION("non-empty list") {
        PyList p;
        p.append(11);
        p.append(22);
        REQUIRE(p[0] == 11);
        REQUIRE(p[1] == 22);
        REQUIRE_THROWS_AS(p[-1], invalid_argument);
        REQUIRE_THROWS_AS(p[2], invalid_argument);

        p[0] = 17;
        REQUIRE(p[0] == 17);
    }
}

TEST_CASE("copy constructor") {
    SECTION("copying") {
        PyList p1;
        p1.append(10);
        p1.append(20);
        p1.append(30);
        p1.append(40);
        p1.append(50);
        REQUIRE(p1.getSize() == 5);
        REQUIRE(p1.getCapacity() == 8);

        PyList p2(p1);
        REQUIRE(p2.getSize() == 5);
        REQUIRE(p2.getCapacity() == 8);
    }
}

TEST_CASE("removeAt") {
    PyList p;
    p.append(11);
    p.append(22);
    p.append(33);
    REQUIRE(p.getCapacity() == 4);
    REQUIRE(p.getSize() == 3);
    REQUIRE(p.removeAt(0) == 11);
    REQUIRE(p.getSize() == 2);
    REQUIRE(p[0] == 22);
    REQUIRE(p[1] == 33);
}
