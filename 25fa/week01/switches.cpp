#include <iostream>

using namespace std;

int main(){
    cout << "Enter a number between 1 and 5: ";
    int x;
    cin >> x;
    switch(x){
        case 1:
            cout << "You entered one" << endl;
            // break;
        case 2:
            cout << "You entered two" << endl;
            break;
        case 3:
            cout << "You entered three" << endl;
            break;
        case 4:
            cout << "You entered four" << endl;
            break;
        case 5:
            cout << "You entered five" << endl;
            break;
        default:
            cout << "You did not enter a number between 1 and 5" << endl;
            break;

    }
    return 0;
}