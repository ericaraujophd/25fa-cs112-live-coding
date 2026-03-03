
#include "List.h"

#include <iostream>
using namespace std;

List::List() {
    mySize = 0;
    myFirst = myLast = nullptr;
}

List::~List() {
    delete myFirst;
}

List::Node::Node(const Item& it, Node* next) {
    myItem = it;
    myNext = next;
}

List::Node::~Node() {
    cout << "deleting node at " << this << endl;
    delete myNext;
}

int List::getSize() const {
    return mySize;
}

void List::prepend(const Item& it) {
    // when mysize == 0, myFirst is null;
    // otherwise, myFirst points to the first node.
    Node* tmp = new Node(it, myFirst);
    if (mySize == 0) {
        myFirst = myLast = tmp;
    } else {
        myFirst = tmp;
    }
    mySize++;
}

// return the first item in the list.
Item List::getFirst() const {
    return myFirst->myItem;
    // return (*myFirst).myItem;
}

// return the first item in the list.
Item List::getLast() const {
    return myLast->myItem;
    // return (*myLast).myItem;
}

string List::toString() const {
    string s = "[";
    // Node* curr = myFirst;
    // while (curr != nullptr) {
    //     s += to_string(curr->myItem) + ' ';
    //     // move curr to the next node.
    //     curr = curr->myNext;
    // }

    for (Node* curr = myFirst; curr != nullptr; curr = curr->myNext) {
        s += to_string(curr->myItem);
        // only add ', ' if we are not looking at the last node.
        if (curr->myNext != nullptr) {
            s += ", ";
        }
    }
    s += "]";

    return s;
}
