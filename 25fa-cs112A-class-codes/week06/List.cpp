#include "List.h"

List::List(){
    myFirst = myLast = nullptr;
    mySize = 0;
}

List::~List(){
    mySize = 0;
}

int List::getSize() const{
    return mySize;
}

bool List::isEmpty() const{
    return (mySize == 0);
}

void List::append(Item it){
    if(mySize == 0){
        Node *node = new Node(it, nullptr);
        myFirst = myLast = node;
        mySize++;
    }
    else{
        Node *node = new Node(it, nullptr);
        myLast->setNext(node);
        myLast = node;
        mySize++;
    }
}

void List::prepend(Item it){
    if(mySize==0){
        Node *node = new Node(it, myFirst);
        myFirst = myLast = node;
        mySize++;
    }
    else{
        Node *node = new Node(it, myFirst);
        myFirst = node;
        mySize++;
    }
}


/// NODE CLASS

List::Node::Node(){
    myItem = -1;
    myNext = nullptr;

}

List::Node::Node(Item it, Node* next){
    myItem = it;
    myNext = next;
}

List::Node::~Node(){
    delete myNext;
}

void List::Node::setNext(Node *next){
    myNext = next;
}