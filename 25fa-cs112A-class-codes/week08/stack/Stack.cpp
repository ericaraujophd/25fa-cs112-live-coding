#include "Stack.h"
#include<stdexcept>

using namespace std;
Stack::Stack(){}

Stack::~Stack(){}

// methods
Item Stack::pop(){
    if(isEmpty()){
        throw range_error("Bad boy!\n");
    }
    Item temp = myList.front();
    myList.pop_front();
    return temp;
}

void Stack::push(Item it){
    myList.push_front(it);
}

Item Stack::peekTop() const{
    return myList.front();
}

bool Stack::isEmpty(){
    return myList.empty();
}
    