#include "PyList.h"

#include <stdexcept>
using namespace std;

PyList::PyList() {
    mySize = 0;
    myCapacity = 0;
    myArray = nullptr;
}

PyList::PyList(const PyList& original) {
    mySize = original.mySize;
    myCapacity = original.myCapacity;
    // myArray = original.myArray;  // shallow copy  WRONG!
    // do a deep copy of the myArray
    myArray = new Item[myCapacity];
    for (int i = 0; i < mySize; i++) {
        myArray[i] = original.myArray[i];
    }
}

PyList::~PyList() {
    // cout << "Help! I'm about to be destroyed!!!" << endl;
    delete[] myArray;
}

int PyList::getSize() const {
    return mySize;
}

int PyList::getCapacity() const {
    return myCapacity;
}

void PyList::append(const Item& it) {
    // if we don't have space for the new item...
    if (mySize == myCapacity) {
        // double our capacity when the array is full.
        // use the ternary operator to be a "cool" kid
        // myCapacity = myCapacity == 0 ? 1 : myCapacity * 2;
        if (myCapacity == 0) {
            myCapacity = 1;
        } else {
            myCapacity *= 2;
        }
        //   allocate more space
        Item* tmp = new Item[myCapacity];
        //   move the old stuff into the new space
        for (int i = 0; i < mySize; i++) {
            tmp[i] = myArray[i];
        }
        //   release the old space.
        delete[] myArray;
        //   use the new space as the permanent space.
        myArray = tmp;
    }
    myArray[mySize] = it;
    mySize++;
}

Item PyList::removeAt(int idx) {
    if (idx >= mySize || idx < 0) {
        throw invalid_argument("bad index, silly goose!");
    }
    Item tmp = myArray[idx];

    for (int i = idx; i < mySize; i++) {
        myArray[i] = myArray[i + 1];
    }

    return tmp;
}

Item PyList::getItem(int idx) const {
    // if the index is bad
    if (idx >= mySize || idx < 0) {
        throw invalid_argument("bad index, silly goose!");
    }
    return myArray[idx];
}

void PyList::setItem(int idx, const Item& it) {
    if (idx >= mySize || idx < 0) {
        throw invalid_argument("bad index, silly goose!");
    }
    myArray[idx] = it;
}

Item& PyList::operator[](int idx) {
    if (idx >= mySize || idx < 0) {
        throw invalid_argument("bad index, silly goose!");
    }
    return myArray[idx];
};

ostream& operator<<(ostream& out, const PyList& p) {
    for (int i = 0; i < p.getSize(); i++) {
        out << p.getItem(i) << ' ';
    }
    return out;
}
