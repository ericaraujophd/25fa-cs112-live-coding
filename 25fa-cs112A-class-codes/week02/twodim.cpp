#include <iostream>

using namespace std;

int main(){
    int twoArr[2][3] = {{1,2,3}, {4,5,6}}; // two rows, three columns

    for(int i=0; i < 2; i++){
        for (int j=0; j<3; j++){
            cout << "(" << i << ", " << j << "): " << twoArr[i][j] << endl;
        }
    }

    int *ptr = &twoArr[0][0];

    cout << *ptr << endl;
    
    ptr++;
    cout << *ptr << endl;
    
    ptr++;
    cout << *ptr << endl;
    
    ptr++;
    cout << *ptr << endl;
    
    ptr++;
    cout << *ptr << endl;
    
    ptr++;
    cout << *ptr << endl;
    
    ptr++;
    cout << *ptr << endl;

    return 0;
}