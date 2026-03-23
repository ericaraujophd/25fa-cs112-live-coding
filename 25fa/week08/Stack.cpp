#include "Stack.h"

void Stack::push(const Item& it) {
    myList.prepend(it);
}

Item Stack::pop() {
    return myList.removeFirst();
}

Item Stack::peekTop() const {
    return myList.getFirst();
}