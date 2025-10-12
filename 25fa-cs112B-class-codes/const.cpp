#include <iostream>

using namespace std;

int main(){
    int x;
    const int AGE = x = 23;
    x = 33;
    cout << AGE << endl; // Output will be 23

    cin >> x;
    cout << x << endl; // Output will be the value entered by the user
    cout << "I survived!" << endl;
    return 0;
}