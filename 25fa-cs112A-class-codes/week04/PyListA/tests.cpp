#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PyList.h"

TEST_CASE("Constructors") {
    SECTION("Default constructor"){
        PyList<int> p;
        REQUIRE(p.getSize() == 0);
    }
    SECTION("append"){
        PyList<int> p;
        p.append(23);
        REQUIRE(p.getSize() == 1);
        p.append(43);
        REQUIRE(p.getSize() == 2);
    }

}

TEST_CASE("to string"){
    PyList<int> p;
    p.append(1);
    p.append(11);
    p.append(111);
    p.append(1111);
    p.append(11111);
    REQUIRE(p.toString() == "1 11 111 1111 11111 ");
    REQUIRE(p.getSize() == 8);
    REQUIRE(p.getCapacity() == 3);

    p.append(2);
    p.append(22);
    p.append(222);

    REQUIRE(p.getSize() == 8);
    REQUIRE(p.getCapacity() == 0);

    p.append(3);

    REQUIRE(p.getSize() == 16);
    REQUIRE(p.getCapacity() == 7);


}

TEST_CASE("copy constructor"){
    SECTION("copying"){
        PyList<int> p1;
        p1.append(10);
        p1.append(20);
        p1.append(30);
        p1.append(40);
        p1.append(50);
        REQUIRE(p1.getSize() == 8);
        REQUIRE(p1.getCapacity() == 3);
        
        PyList<int> p2 = p1;
        REQUIRE(p2.getSize() == 8);
        REQUIRE(p2.getCapacity() == 3);

        REQUIRE(p1.toString() == p2.toString());


    }
}

TEST_CASE("template class"){
    SECTION("strings"){
        PyList<char> p;
        p.append('M');
        p.append('O');
        p.append('Y');
        cout << p << endl;
    }

    SECTION("doubles"){
        PyList<double> pd;
        pd.append(1.5);
        pd.append(2.5);
        pd.append(3.5);
        pd.append(-3.5);
        pd.append(-2.1);
        REQUIRE(pd.getSize() == 8);
        cout << pd << endl;
    }
}