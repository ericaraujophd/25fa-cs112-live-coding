#include<map>
#include <iostream>

using namespace std;

int main(){
    map<int, char> myMap;

    myMap[1] = 'A';
    myMap[2] = 'B';
    myMap[3] = 'C';

    cout << "Size of myMap: " << myMap.size() << endl;
    cout << "Value for key 2: " << myMap[2] << endl;

    return 0;
}