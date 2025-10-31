#include "Cirqueue.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Cirqueue::Cirqueue(){
    capacity = 5;
    myArray = new Item[capacity];
    myFirstIndex = 0; // the error was here!
    myLastIndex = capacity - 1; // and here!
    mySize = 0;
}

Cirqueue::Cirqueue(int cap){
    capacity = cap;
    myArray = new Item[capacity];
    myFirstIndex = 0; // the error was here
    myLastIndex = capacity - 1; // and here too!
    mySize = 0;
}

Cirqueue::~Cirqueue(){
    delete myArray;
}

bool Cirqueue::isEmpty() const{
    return (mySize == 0);
}
bool Cirqueue::isFull() const{
    return (mySize == capacity);
}

Item Cirqueue::peekFirst() const{
    if(! isEmpty()){
        return myArray[myFirstIndex];
    }
    throw range_error("Empty, my dear!\n");
}
Item Cirqueue::peekLast() const{
    if(! isEmpty()){
        return myArray[myLastIndex];
    }
    throw range_error("Empty, my dear!\n");
}

void Cirqueue::add(Item it){
    if(!isFull()){
        myLastIndex = (myLastIndex + 1) % capacity;
        myArray[myLastIndex] = it;
        mySize++;
        return;
    }
    throw range_error("I'm full of this nonsense!\n");
}
Item Cirqueue::remove(){
    if(!isEmpty()){
        myFirstIndex = (myFirstIndex + 1) % capacity;
        mySize--;
        return myArray[myFirstIndex-1];
    }
    throw range_error("You've emptied my heart!\n");
}


void Cirqueue::printArray() const{
    for(int i = myFirstIndex; i == myLastIndex; i = (i + 1)%capacity){
        cout << i << ": " << myArray[i] << endl;
    }
}
