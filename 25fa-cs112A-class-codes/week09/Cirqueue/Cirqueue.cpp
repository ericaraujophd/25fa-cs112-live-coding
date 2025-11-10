#include "Cirqueue.h"
#include <stdexcept>

using namespace std;

Cirqueue::Cirqueue(){
    QUEUE_CAPACITY = 5;
    myArray = new Item[QUEUE_CAPACITY];
    mySize = 0;
    myFirstIndex = 0;
    myLastIndex = QUEUE_CAPACITY - 1;
}

Cirqueue::Cirqueue(int capacity){
    QUEUE_CAPACITY = capacity;
    myArray = new Item[QUEUE_CAPACITY];
    mySize = 0;
    myFirstIndex = 0;
    myLastIndex = QUEUE_CAPACITY - 1;
}

Cirqueue::~Cirqueue(){
    delete myArray;
    mySize = 0;
}

// // methods of the queue
void Cirqueue::add(Item it){
    if(isFull()){
        throw range_error("Queue is FULL, you fool.\n");
    }

    myLastIndex = (myLastIndex + 1) % QUEUE_CAPACITY;
    myArray[myLastIndex] = it;
    mySize++;
}

Item Cirqueue::remove(){
    if(isEmpty()){
        throw range_error("Queue is empty, kiddo.\n");
    }
    Item temp = myArray[myFirstIndex];
    myFirstIndex = (myFirstIndex + 1) % QUEUE_CAPACITY;
    mySize--;
    return temp;
}

Item Cirqueue::peekFirst() const{
    return myArray[myFirstIndex];
}

Item Cirqueue::peekLast() const{
    return myArray[myLastIndex];
}

bool Cirqueue::isEmpty() const{
    return (mySize == 0);
}
bool Cirqueue::isFull() const{
    return (mySize == QUEUE_CAPACITY);
}