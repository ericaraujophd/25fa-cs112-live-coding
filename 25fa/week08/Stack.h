#include "List.h"
using namespace std;

typedef int Item;

class Stack {
public:
    Stack();

    void push(const Item& it);
    Item pop();
    Item peekTop() const;
    bool isFull() const;
    bool isEmpty() const;

private:
    Vec myVector;
};