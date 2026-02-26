#ifndef _PYLIST_H_
#define _PYLIST_H_

#include <iostream>
using namespace std;

typedef int Item;

class PyList {
public:
    PyList();
    ~PyList();  // destructor

    PyList(const PyList& p);

    int getSize() const;
    int getCapacity() const;
    void append(const Item& it);
    Item removeAt(int idx);

    Item getItem(int idx) const;
    void setItem(int idx, const Item& it);
    Item& operator[](int idx);

private:
    // the number of items in the array
    int mySize;
    // the max number of items we can store
    int myCapacity;
    // the array holding the values in the list
    Item* myArray;
};

ostream& operator<<(ostream& out, const PyList& p);

#endif