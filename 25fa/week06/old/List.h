#ifndef _LIST_H_
#define _LIST_H_

typedef int Item;

class List {
public:
    List();
    int getSize() const;
    void prepend(const Item& it);

public:
    class Node {
    public:
        Node(const Item& it);

    private:
        Item myItem;
        Node* myNext;
    };

    int mySize;
    Node* myFirst;
    Node* myLast;
};

#endif