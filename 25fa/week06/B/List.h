#ifndef _LIST_H_
#define _LIST_H_

#include <string>
using namespace std;

typedef int Item;

class List {
public:
    List();
    ~List();
    int getSize() const;
    void prepend(const Item& it);
    Item getFirst() const;
    Item getLast() const;
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