#include <iostream>
#include <string>
#include "PyList.h"

using namespace std;

int main(){
    PyList p;
    p.append(1);
    p.append(11);
    p.append(111);
    p.append(1111);
    p.append(11111);
    cout << p << endl;
    if(p.getSize() == 8) cout << "Size ok!\n";
    if(p.getCapacity() == 3) cout << "Capacity ok!\n";

    p.append(2);
    p.append(22);
    p.append(222);

    if(p.getSize() == 8) cout << "Size ok!\n";
    if(p.getCapacity() == 0) cout << "Capacity ok!\n";

    p.append(3);

    if(p.getSize() == 16) cout << "Size ok!\n";
    if(p.getCapacity() == 7) cout << "Capacity ok!\n";
}