#include "Pair.h"

// Constructors

// default constructor
Pair::Pair() {
    myFirst = 0;
    mySecond = 0;
}

// explicit-value constructor
Pair::Pair(int first, int second) {
    myFirst = first;
    mySecond = second;
}

// Implementation of the getters

int Pair::getFirst() const {
    return myFirst;
}

int Pair::getSecond() const {
    return mySecond;
}

// Implementation of the setters

void Pair::setFirst(int first) {
    myFirst = first;
}

void Pair::setSecond(int second) {
    mySecond = second;
}

string Pair::toString() const {
    return "<" + to_string(myFirst) + ", " + to_string(mySecond) + ">";
}

ostream& operator<<(ostream& out, const Pair& p) {
    string str = p.toString();
    out << str;
    return out;
}
