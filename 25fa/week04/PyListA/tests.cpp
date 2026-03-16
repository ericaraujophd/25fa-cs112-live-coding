#define CATCH_CONFIG_MAIN
#include <sstream>

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
        REQUIRE(p.getCapacity() == 0);
        REQUIRE(p.getSize() == 0);
        p.append(11);
        REQUIRE(p.getItem(0) == 11);
        REQUIRE(p.getSize() == 1);
        REQUIRE(p.getCapacity() == 1);
    }
    SECTION("to list with 1 item") {
        PyList p;
        p.append(11);
        p.append(22);
        REQUIRE(p.getSize() == 2);
        REQUIRE(p.getCapacity() == 2);
        REQUIRE(p.getItem(0) == 11);
        REQUIRE(p.getItem(1) == 22);

        p.append(33);
        REQUIRE(p.getSize() == 3);
        REQUIRE(p.getCapacity() == 4);
        REQUIRE(p.getItem(0) == 11);
        REQUIRE(p.getItem(1) == 22);
        REQUIRE(p.getItem(2) == 33);

        p.append(44);
        REQUIRE(p.getSize() == 4);
        REQUIRE(p.getCapacity() == 4);
        REQUIRE(p.getItem(0) == 11);
        REQUIRE(p.getItem(1) == 22);
        REQUIRE(p.getItem(2) == 33);
        REQUIRE(p.getItem(3) == 44);

        p.append(55);
        REQUIRE(p.getSize() == 5);
        REQUIRE(p.getCapacity() == 8);
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
    PyList p4;
    p4.append(11);
    p4.append(22);
    p4.append(33);
    p4.append(44);

    // cout << p4 << endl;
    // Output should look like this:
    // 11 22 33 44
    ostringstream oss;
    oss << p4;
    REQUIRE(oss.str() == "11 22 33 44 ");
}

TEST_CASE("indexing with []") {
    SECTION("empty PyList") {
        PyList p;
        REQUIRE_THROWS_AS(p[0], invalid_argument);
        REQUIRE_THROWS_AS(p[-1], invalid_argument);
        REQUIRE_THROWS_AS(p[1], invalid_argument);
    }
    SECTION("non-empty") {
        PyList p;
        p.append(11);
        p.append(22);
        p.append(33);
        REQUIRE(p[0] == 11);
        REQUIRE(p[1] == 22);
        REQUIRE(p[2] == 33);
        p[0] = 7;
        REQUIRE(p[0] == 7);
        // here is where the destructor is called.
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

        // for (int i = 0; i < p2.getSize(); i++) {
        //     REQUIRE(p2[i] == p1[i]);
        // }

        // REQUIRE(p1.toString() == p2.toString());
    }
}

TEST_CASE("removeAt") {
    SECTION("from empty array") {
        PyList p;
        REQUIRE_THROWS_AS(p.removeAt(0), invalid_argument);
    }
    SECTION("from array with 3 items in it") {
        PyList p;
        p.append(11);
        p.append(22);
        p.append(33);
        REQUIRE(p.removeAt(0) == 11);
        REQUIRE(p.getSize() == 2);
        REQUIRE(p.getCapacity() == 4);
        REQUIRE(p[0] == 22);
        REQUIRE(p[1] == 33);
        cout << p;
    }
}

TEST_CASE("== comparision") {
    SECTION("empty") {
        PyList p;
        PyList p2;
        REQUIRE(p == p2);
        if (p.operator==(p2)) }
    SECTION("non-empty") {
        PyList p;
        for (int i = 0; i < 10000; i++) {
            p.append(i * 3);
        }
        PyList p2;
        for (int i = 0; i < 10000; i++) {
            p2.append(i * 3);
        }
        REQUIRE(p == p2);
        p2.append(7);
        REQUIRE(!(p == p2));
    }
}
