#ifndef _PYLIST_H_
#define _PYLIST_H_

#include<iostream>

using namespace std;

template<class Item>
class PyList{
    public:
        // default constructor
        PyList();
        // copy constructor
        PyList(const PyList &other);
        
        // destructor
        ~PyList();
        
        // getters
        int getSize() const;
        int getCapacity() const;

        void append(Item);

        string toString() const;
    private:
        Item *arr;
        int size;
        int capacity;
};

template <class Item>
ostream &operator<< (ostream &out, const PyList<Item> &p);


////////


// default constructor
template<class Item>
PyList<Item>::PyList(){
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

    for(int i=0; i < size - capacity; i++){
        arr[i] = other.arr[i];
    }
    
}

// destructor
template<class Item>
PyList<Item>::~PyList(){
    delete []arr;
    // cout << "I am dyyyyiiiiiinnggg!!" << endl;
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

    if(size == 1){
        Item *tempArr = new Item[2];
        tempArr[0] = arr[0];
        tempArr[1] = it;
        size = 2;
        capacity = 0;
        
        delete []arr;
        arr = tempArr;
        return;
    }
    
    if(capacity == 0){
        // if size > 2
        size = size * 2;
        Item *tempArr = new Item[size];
        for(int i=0; i < size/2; i++){
            tempArr[i] = arr[i];
        }
        tempArr[size/2] = it;
        capacity = size/2 - 1;

        delete []arr;
        arr = tempArr;
    }
    else{
        arr[size - capacity] = it;
        capacity--;
    }

    // Item *newArr = new Item[size+1];

    // for(int i = 0; i < size; i++){
    //     newArr[i] = arr[i];
    // }
    // newArr[size] = it;
    // size++;

    // delete []arr;
    // arr = newArr;
}

template<class Item>
string PyList<Item>::toString() const{
    string str = "";

    for(int i=0; i < (size-capacity); i++){
        str += to_string(arr[i]);
        str += " ";
    }

    return str;
}

template<class Item>
ostream &operator<< (ostream &out, const PyList<Item> &p){
    out << p.toString();
    return out;
}

#endif