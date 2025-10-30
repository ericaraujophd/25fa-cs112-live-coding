#include "List.h"
#include <iostream>

using namespace std;
// Node!!!!!

List::Node::Node(){
    myItem = -1;
    myNext = nullptr;
}

List::Node::Node(Item it, Node* next){
    myItem = it;
    myNext = next;
}

List::Node::~Node(){
    // cout << "I'm about to be destroyed! ";
    // cout << myItem;
    // cout << endl;
    delete myNext;
    // cout << "Bye bye";
    // cout << myItem;
    // cout << endl;
}

Item List::Node::getItem() const{
    return myItem;
}

void List::Node::setNext(Node* next){
    myNext = next;
}

List::Node* List::Node::getNext() const{
    return myNext;
}

// CLASS LIST

List::List(){
    mySize = 0;
    myFirst = myLast = nullptr;
}

List::~List(){
    // cout << "Some criminal want to delete me! A LIST!" << endl;
    delete myFirst;
}

int List::getSize() const{
    return mySize;
}

Item List::getFirst() const{
    return myFirst->getItem();
    // return (*myFirst).getItem();
}

Item List::getLast() const{
    return myLast->getItem();
}
    
bool List::isEmpty() const{
    return (mySize == 0);
}

// insertions
void List::append(Item it){
    if(mySize == 0){
        Node *newNode = new Node(it, nullptr);
        myFirst = myLast = newNode;
        mySize++;
    }
    else{
        Node *newNode = new Node(it, nullptr);
        myLast->setNext(newNode);
        myLast = newNode;
        mySize++;
        
    }
}
void List::prepend(Item it){
    if(mySize == 0){
        Node *newNode = new Node(it, nullptr);
        myFirst = myLast = newNode;
        mySize++;
    }
    else{
        Node *newNode = new Node(it, myFirst);
        myFirst = newNode;
        mySize++;
    }
}


Item List::removeFirst(){
    Node* temp = myFirst;
    Item tempItem = myFirst->getItem();
    myFirst = myFirst->getNext();
    temp->setNext(nullptr);
    delete temp;
    mySize--;
    return tempItem;
}