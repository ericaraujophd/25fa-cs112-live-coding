#include <iostream>

using namespace std;

void print(int *arr, int size){
    for(int i=0; i< size; i++){
        cout << arr[i] << endl;
    }
    // cout << "arr inside print: " << arr << endl;
    
}

void print2(int arr[], int size){
    for(int i=0; i< size; i++){
        cout << arr[i] << endl;
    }
    // cout << "arr inside print2: " << arr << endl;
}

int main() {
   int vals[] = { 1, 3, 4 };
//    cout << "vals inside main: " << vals << endl;
   int val = 7;
//    print(vals, 3);
    cout << "-------------------\n";
    print2(vals, 3);
    cout << "-------------------\n";
    print2(&val, 1);
    cout << "-------------------\n";
    print2(vals, 5);
    cout << "-------------------\n";
    print2(&val, 3);
    cout << "-------------------\n";
}
