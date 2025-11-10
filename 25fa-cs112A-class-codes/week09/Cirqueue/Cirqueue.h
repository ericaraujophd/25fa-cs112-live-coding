#ifndef _CIRQUEUE_H_
#define _CIRQUEUE_H_

typedef int Item;
class Cirqueue {
public:
    Cirqueue();
    Cirqueue(int capacity);
    ~Cirqueue();

    // methods of the queue
    void add(Item it);
    Item remove();
    Item peekFirst() const;
    Item peekLast() const;

    bool isEmpty() const;
    bool isFull() const;

private:
    int QUEUE_CAPACITY;
    int mySize;
    int myFirstIndex;
    int myLastIndex;
    Item *myArray;
};

#endif