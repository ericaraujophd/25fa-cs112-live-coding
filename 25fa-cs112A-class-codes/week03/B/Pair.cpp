#include "Pair.h"

// Default Constructor
Pair::Pair(){
    myFirst = 0;
    mySecond = 0;
}

// Explicit-value Constructor
Pair::Pair(int first, int second){
    myFirst = first;
    mySecond = second;
}

// getters
int Pair::getFirst() const{
    return myFirst;
}

int Pair::getSecond() const{
    return mySecond;
}

// setters
void Pair::setFirst(int first){
    myFirst = first;
}

void Pair::setSecond(int second){
    mySecond = second;
}

// toString
string Pair::toString() const{
    return "<" + to_string(myFirst) + ", " + to_string(mySecond) + ">";
}

ostream &operator<<(ostream &out, const Pair &p){
    out << p.toString();
    return out;
}

Pair &operator+(const Pair &p1, const Pair &p2){
    int first = p1.getFirst()+p2.getFirst();
    int second = p1.getSecond()+p2.getSecond();
    Pair *p3 = new Pair(first, second);
    return *p3;
}