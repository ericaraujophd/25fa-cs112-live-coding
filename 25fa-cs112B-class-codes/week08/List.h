#ifndef _LIST_H_
#define _LIST_H_

typedef int Item;

class List{
public:
    List();
    // List(Item it);
    ~List();

    int getSize() const;
    Item getFirst() const;
    Item getLast() const;
    bool isEmpty() const;

    // insertions
    void append(Item it);
    void prepend(Item it);

    Item removeFirst();

private:
    // class NODE
    class Node{
    public:
        Node();
        Node(Item it, Node* next);
        ~Node();

        Item getItem() const;
        Node* getNext() const;
        void setNext(Node* next);
    private:
        Item myItem;
        Node* myNext;
    };
    Node* myFirst;
    Node* myLast;
    int mySize;
};


#endif