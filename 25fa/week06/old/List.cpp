#include "List.h"

#include <iostream>
using namespace std;

List::List() {
    myFirst = myLast = nullptr;
    mySize = 0;
}

List::~List() {
    mySize = 0;
    cout << "calling the destructor of list" << endl;
    delete myFirst;
}

int List::getSize() const {
    return mySize;
}

bool List::isEmpty() const {
    return (mySize == 0);
}

void List::append(Item it) {
    if (mySize == 0) {
        Node* node = new Node(it, nullptr);
        myFirst = myLast = node;
        mySize++;
    } else {
        Node* node = new Node(it, nullptr);
        myLast->setNext(node);
        myLast = node;
        mySize++;
    }
}

void List::prepend(Item it) {
    if (mySize == 0) {
        Node* node = new Node(it, myFirst);
        myFirst = myLast = node;
        mySize++;
    } else {
        Node* node = new Node(it, myFirst);
        myFirst = node;
        mySize++;
    }
}

void List::deleteNode(Item it) {
    // Node *prevNode = myFirst;
    // Node *iterNode = myFirst;
    // while(iterNode != nullptr){
    //     if(iterNode->getItem() == it){
    //         // remove it here

    //     }
    // }
}

/// NODE CLASS

Item List::Node::getItem() const {
    return myItem;
}

List::Node::Node() {
    myItem = -1;
    myNext = nullptr;
}

List::Node::Node(Item it, Node* next) {
    myItem = it;
    myNext = next;
}

List::Node::~Node() {
    cout << "Starting to delete node ";
    cout << myItem;
    cout << endl;
    delete myNext;
    cout << "I am going to disappear now!";
    cout << myItem;
    cout << endl;
}

void List::Node::setNext(Node* next) {
    myNext = next;
}