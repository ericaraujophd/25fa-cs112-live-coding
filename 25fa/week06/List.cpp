
#include "List.h"

List::List() {
    mySize = 0;
    myFirst = myLast = nullptr;
}

int List::getSize() const {
    return mySize;
}

void List::prepend(const Item& it) {
    // make new node
    // incrfement mySize
    // put the value in the new node
    // set myNext in the new node to nullptr
    // myFirst and myLast to new node.

    Node* tmp = new Node(it);
    if (mySize == 0) {
        myFirst = myLast = tmp;
    }
    mySize++;
}

// constructor for inner Node class.
List::Node::Node(const Item& it) {
    myItem = it;
    myNext = nullptr;
}