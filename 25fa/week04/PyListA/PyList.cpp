#include "PyList.h"

#include <stdexcept>
using namespace std;

PyList::PyList() {
    mySize = 0;
    myCapacity = 0;
    myArray = nullptr;
}

PyList::~PyList() {
    // cout << "Help, I'm being destroyed!" << endl;
    delete[] myArray;
}

// copy constructor -- using deep copy
PyList::PyList(const PyList& original) {
    mySize = original.mySize;
    myCapacity = original.myCapacity;
    // myArray = original.myArray;  // shallow copy: WRONG

    myArray = new Item[myCapacity];
    for (int i = 0; i < mySize; i++) {
        myArray[i] = original.myArray[i];
    }
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
        // what the "cool" kids would write:
        // myCapacity = myCapacity == 0 ? 1 : myCapacity * 2;
        if (myCapacity == 0) {
            myCapacity = 1;
        } else {
            myCapacity *= 2;
        }
        // allocate more space
        Item* tmp = new Item[myCapacity];

        // move the old stuff into the new space
        // this loop is slow when the array gets big.
        for (int i = 0; i < mySize; i++) {
            tmp[i] = myArray[i];
        }
        // release the old space.
        delete[] myArray;
        // use the new space as the permanent space.
        myArray = tmp;
    }
    myArray[mySize] = it;
    mySize++;
}

Item PyList::getItem(int idx) const {
    // if the index is bad
    if (idx < 0 || idx >= mySize) {
        throw invalid_argument("bad index, silly goose!");
    }
    return myArray[idx];
}

void PyList::setItem(int idx, const Item& it) {
    if (idx < 0 || idx >= mySize) {
        throw invalid_argument("bad index, silly goose!");
    }
    myArray[idx] = it;
}

Item& PyList::operator[](int idx) {
    if (idx < 0 || idx >= mySize) {
        throw invalid_argument("bad index, silly goose!");
    }
    return myArray[idx];
}

// const Item& PyList::operator[](int idx) const {
//     if (idx < 0 || idx >= mySize) {
//         throw invalid_argument("bad index, silly goose!");
//     }
//     return myArray[idx];
// }

Item PyList::removeAt(int idx) {
    if (idx < 0 || idx >= mySize) {
        throw invalid_argument("bad index, silly goose!");
    }
    Item tmp = myArray[idx];

    for (int i = idx; i < mySize - 1; i++) {
        myArray[i] = myArray[i + 1];
    }
    mySize--;

    return tmp;
}

bool PyList::operator==(const PyList& rhs) const {
    if (mySize != rhs.mySize) {
        return false;
    }
    // compare contents of the arrays.
    for (int i = 0; i < mySize; i++) {
        if (myArray[i] != rhs.myArray[i]) {
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& out, const PyList& p) {
    for (int i = 0; i < p.getSize(); i++) {
        out << p.getItem(i) << ' ';
    }
    return out;
}
