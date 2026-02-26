#include <iostream>

using namespace std;


void printArray(int arr[][4], int rows, int cols){
    for(int i=0; i < rows; i++){
        for(int j=0; j < cols; j++){
            cout << "(" << i << ", " << j << "): " << arr[i][j] << "\n";
        }
    }

}

int main(){
    int twoArr[2][4] = {{1,2,3,4}, {9,8,7,6}}; 

    printArray(twoArr, 2, 4);
    
    // cout << "=======================\n";
    // int *ptr = &twoArr[0][0];

    // cout << *ptr << endl;
    
    // ptr++;
    // cout << *ptr << endl;
    // ptr++;
    // cout << *ptr << endl;
    // ptr++;
    // cout << *ptr << endl;
    // ptr++;
    // cout << *ptr << endl;
    // ptr++;
    // cout << *ptr << endl;
    // ptr++;
    // cout << *ptr << endl;
    


    return 0;
}