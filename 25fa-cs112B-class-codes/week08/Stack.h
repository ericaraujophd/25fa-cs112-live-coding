#include "List.h"

typedef int Item;

class Stack{
    public:
        void push(Item it);
        Item pop();

        Item peekTop() const;
    private:
        List myList;

};