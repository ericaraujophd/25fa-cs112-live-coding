#ifndef _PAIR_H_
#define _PAIR_H_

#include <string> 
using namespace std;

typedef int Item;

class Pair{
    public:
        // default constructor
        Pair();
        // explicit-value constructor
        Pair(Item, Item);

        // getters
        Item getFirst() const;
        Item getSecond() const;
        // setters
        void setFirst(Item);
        void setSecond(Item);

        // toString
        string toString() const;
    private:
        Item myFirst;
        Item mySecond;
};

ostream &operator<<(ostream &out, const Pair &p);
Pair &operator+(const Pair &p1, const Pair &p2);

#endif