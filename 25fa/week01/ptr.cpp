#include <iostream>

using namespace std;

int main(){
    int y = 42;
    int *ptr = &y;

    cout << "Value of ptr: " << ptr << endl;
    cout << "Value of *ptr: " << *ptr << endl;
    cout << "Address of y: " << &y << endl;
    cout << "Address of ptr:" << &ptr << endl;

    int zeta = 61;

    ptr = &zeta;

    *ptr = 92;

    cout << *ptr << endl;
    cout << zeta << endl;

    return 0;
}