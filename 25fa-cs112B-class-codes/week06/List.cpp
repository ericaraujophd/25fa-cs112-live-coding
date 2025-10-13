#include "List.h"

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

}

Item List::Node::getItem() const{
    return myItem;
}

void List::Node::setNext(Node* next){
    myNext = next;
}

// CLASS LIST

List::List(){
    mySize = 0;
    myFirst = myLast = nullptr;
}

List::~List(){}

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