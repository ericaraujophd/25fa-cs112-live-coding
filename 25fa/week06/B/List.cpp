
#include "List.h"

#include <iostream>
using namespace std;

List::List() {
    mySize = 0;
    myFirst = myLast = nullptr;
}

List::~List() {
    // delete the first node in the chain.
    delete myFirst;
}

List::Node::Node(const Item& it, Node* next) {
    myItem = it;
    myNext = next;
}

List::Node::~Node() {
    // call this method on the next Node
    cout << "help I'm going away!" << this << endl;
    delete myNext;
}

int List::getSize() const {
    return mySize;
}

Item List::getFirst() const {
    // return (*myFirst).myItem;
    return myFirst->myItem;
}

Item List::getLast() const {
    return myLast->myItem;
}

void List::prepend(const Item& it) {
    // When list is empty, myFirst is null -- perfect.
    // When list is empty myFirst points to the
    // first node, which is what the new node should
    // point to!!!  It is as if we planned this?!
    Node* newNode = new Node(it, myFirst);
    myFirst = newNode;
    if (mySize == 0) {
        myLast = newNode;
    }
    mySize++;
}

string List::toString() const {
    string s = "[";
    // Node* curr = myFirst;
    // while (curr != nullptr) {
    //     s += to_string(curr->myItem) + " ";
    //     // move curr to the next node in the chain.
    //     curr = curr->myNext;
    // }

    for (Node* curr = myFirst; curr != nullptr; curr = curr->myNext) {
        s += to_string(curr->myItem);
        if (curr->myNext != nullptr) {
            s += ", ";
        }
    }

    s += "]";
    return s;
}
