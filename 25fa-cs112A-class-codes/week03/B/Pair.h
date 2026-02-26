#ifndef _PAIR_H_
#define _PAIR_H_

#include <string>
using namespace std;

typedef int Item;

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

// Define << for when left operand is an ostream and right is a Pair object
ostream& operator<<(ostream& out, const Pair& p);

#endif