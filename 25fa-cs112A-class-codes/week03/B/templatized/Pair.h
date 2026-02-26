#ifndef _PAIR_H_
#define _PAIR_H_

#include <string>
using namespace std;

template <class Item>
class Pair {
public:
    // constructors
    Pair();
    Pair(Item first, Item second);

    // getters
    Item getFirst() const;
    Item getSecond() const;

    // setters
    void setFirst(Item newVal);
    void setSecond(Item newVal);

    // toString
    string toString() const;

private:
    Item myFirst;
    Item mySecond;
};

// default constructor
template <class Item>
Pair<Item>::Pair() {
    myFirst = 0;
    mySecond = 0;
}

// explicit-value constructor
template <class Item>
Pair<Item>::Pair(Item first, Item second) {
    myFirst = first;
    mySecond = second;
}

// Implementation of the getters

template <class Item>
Item Pair<Item>::getFirst() const {
    return myFirst;
}

template <class Item>
Item Pair<Item>::getSecond() const {
    return mySecond;
}

// Implementation of the setters

template <class Item>
void Pair<Item>::setFirst(Item first) {
    myFirst = first;
}

template <class Item>
void Pair<Item>::setSecond(Item second) {
    mySecond = second;
}

template <class Item>
string Pair<Item>::toString() const {
    return "<" + to_string(myFirst) + ", " + to_string(mySecond) + ">";
}

template <class Item>
ostream& operator<<(ostream& out, const Pair<Item>& p) {
    string str = p.toString();
    out << str;
    return out;
}

#endif