#ifndef _PYLIST_H_
#define _PYLIST_H_

#include <iostream>
#include <string>
using namespace std;

template<class Item>
class PyList {
public:
    // constructor
    PyList();

    // copy constructor
    PyList(const PyList& other);

    // destructor
    ~PyList();

    // getters
    int getSize() const;
    int getCapacity() const;
    Item &getItemAtIndex(int idx);
    void append(Item);

    string toString() const;
    // PyList& operator=(const PyList& p);
    
    private:
    Item* arr;
    int size;
    int capacity;
};

template <class Item>
ostream& operator<<(ostream& out, const PyList<Item>& p);

template <class Item>
Item &PyList<Item>::getItemAtIndex(int idx){
    return arr[idx];
}

// default constructor
template<class Item>
PyList<Item>::PyList(){
    // cout << "I am alive! " << endl;
    size = 0;
    capacity = 0;
    arr = nullptr;
}

// copy constructor
template<class Item>
PyList<Item>::PyList(const PyList<Item> &other){
    size = other.size;
    capacity = other.capacity;

    arr = new Item[size];
    for(int i=0; i < size-capacity; i++){
        arr[i] = other.arr[i];
    }
}

// destructor
template<class Item>
PyList<Item>::~PyList(){
    delete []arr;
    // cout << "I am dyyyyyiiiiiinnnnnggggg!!" << endl;
}

// getters
template<class Item>
int PyList<Item>::getSize() const{
    return size;
}

template<class Item>
int PyList<Item>::getCapacity() const{
    return capacity;
}

template<class Item>
void PyList<Item>::append(Item it){
    if(size == 0){
        arr = new Item[1];
        arr[0] = it;
        size = 1;
        capacity = 0;
        return;
    }
    if(capacity == 0){
        // we need to double the size!!!
        size = size * 2;
        Item *newArr = new Item[size];

        for(int i=0; i < size/2; i++){
            newArr[i] = arr[i];
        }

        newArr[size/2] = it;

        capacity = size/2 - 1;
        delete []arr;
        arr = newArr;
    }
    else{
        // slap the new value in the array
        arr[size - capacity] = it;
        capacity--;
    }

    // Item *newArr = new Item[size+1];
    // for(int i=0; i < size; i++){
    //     newArr[i] = arr[i];
    // }

    // newArr[size] = it;
    // delete []arr;
    // arr = newArr;

    // size++;
}

template<class Item>
string PyList<Item>::toString() const{
    string str = "";
    for(int i=0; i < size - capacity; i++){
        str += to_string(arr[i]);
        str += " ";
    }

    return str;
}

template<class Item>
ostream & operator<<(ostream &out, const PyList<Item> &p){
    for(int i=0; i < p.getSize() - p.getCapacity(); i++){
        out << p.getItemAtIndex(i);
        out << " ";
    }
    // out << p.toString();
    return out;
}


#endif