#include <iostream>
#include <stdexcept>

using namespace std;

int getVal(int arr[], int val, int size){
    if (val < 0 || val >= size){
        throw invalid_argument("dont do that my dear, you are hurting me...");
    }
    return arr[val];
}

int main() {
    int arrIntegers[5] = {1, 2, 3, 4, 5};

    cout << "What is the index you want to retrieve? ";
    int idx;
    cin >> idx;
    try {
        cout << getVal(arrIntegers, idx, 5) << endl;
    } catch (const invalid_argument & e){
        cerr << "Some thing went wrong: " << e.what() << endl;
    }

    return 0;
}