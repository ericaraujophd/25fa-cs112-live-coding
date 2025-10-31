#ifndef _CIRQUEUE_H_
#define _CIRQUEUE_H_

typedef int Item;

class Cirqueue {
    public:
        Cirqueue();
        Cirqueue(int size);
        ~Cirqueue();

        bool isEmpty() const;
        bool isFull() const;

        Item peekFirst() const;
        Item peekLast() const;

        void add(Item it);
        Item remove();

        void printArray() const;
    private:
        Item *myArray;
        int myFirstIndex;
        int myLastIndex;
        int mySize;
        int capacity;
};

#endif