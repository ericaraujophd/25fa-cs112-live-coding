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

        p.append(1);
        REQUIRE(p.getSize() == 1);

        p.append(2);
        REQUIRE(p.getSize() == 2);
    }

    SECTION("<<"){
        PyList<int> p;

        p.append(1);
        p.append(11);
        p.append(111);
        p.append(1111);
        p.append(11111);

        // REQUIRE(p.toString() == "1 11 111 1111 11111 ");

        REQUIRE(p.getSize() == 8);
        REQUIRE(p.getCapacity() == 3);
    }
    
    SECTION("copy constructor"){
        PyList<int> p1;
        p1.append(1);
        p1.append(2);
        p1.append(3);
        p1.append(4);
        p1.append(5);

    }

}

TEST_CASE("templates"){
    SECTION("double"){
    PyList<double> pd;

    pd.append(1.2);
    pd.append(0.2);
    pd.append(-1.6);
    pd.append(9.2345);
    pd.append(1.0100101);

    REQUIRE(pd.getCapacity()==3);
    REQUIRE(pd.getSize()==8);

    cout << pd << endl;
    }

    SECTION("string"){
        PyList<string> ps;

        ps.append("Neal is gone");
        ps.append("No he is not");
        ps.append("Actually he is");
        ps.append("Gavin!!!!!");

        cout << ps << endl;

    }
}
