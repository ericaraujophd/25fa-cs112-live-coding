#ifndef _LIST_H_
#define _LIST_H_

#include <ostream>
using namespace std;

typedef int Item;

class List {
public:
    List();
    ~List();
    int getSize() const;
    Item getFirst() const;
    Item getLast() const;
    void prepend(const Item& it);
    string toString() const;

private:
    class Node {
    public:
        Node(const Item& it, Node* next);
        ~Node();

        Item myItem;
        Node* myNext;
    };

    int mySize;
    Node* myFirst;
    Node* myLast;
};

#endif