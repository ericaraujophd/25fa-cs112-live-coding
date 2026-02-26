#include <iostream>

using namespace std;

int main(){
    int y = 10;
    int *x = &y;

    cout << "Value of x: " << x << endl;
    cout << "Value of the memory address of x: " << &x << endl;
    cout << "Value of y: " << *x << endl;

    int zeta = 42;

    x = &zeta;
    
    cout << "Value of *x: " << *x << endl;


    return 0;
}