#ifndef _LIST_H_
#define _LIST_H_

typedef int Item;

class List {
public:
    // constructors
    List();
    ~List();

    // getters
    int getSize() const;
    bool isEmpty() const;

    // setters
    void append(Item it);
    void prepend(Item it);

    // deletion
    void deleteNode(Item it);

private:
    class Node {
    public:
        Node();
        Node(Item it, Node* next);
        ~Node();

        void setNext(Node *next);
        Item getItem() const;

    private:
        Item myItem;
        Node* myNext;
    };

    Node* myFirst;
    Node* myLast;
    int mySize;
};

#endif