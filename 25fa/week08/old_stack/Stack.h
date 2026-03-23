#ifndef _STACK_H_
#define _STACK_H_

#include <list>

using namespace std;
typedef int Item;

class Stack {
public:
    Stack();
    ~Stack();

    // methods
    Item pop();
    void push(Item it);
    Item peekTop() const;
    bool isEmpty();
    
private:
    list<Item> myList;

};

#endif