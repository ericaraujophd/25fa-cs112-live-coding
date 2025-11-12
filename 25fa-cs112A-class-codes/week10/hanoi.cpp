#include <iostream>
using namespace std;

void move(int nDisks, char src, char dst, char aux){
    if(nDisks == 1){
        cout << "Move disk from " << src << " to " << dst << endl;
    }
    else{
        move(nDisks-1, src, aux, dst);
        move(1, src, dst, aux);
        move(nDisks-1, aux, dst, src);
    }
}

int main(){
    cout << "How many disks, bro? ";
    int n;
    cin >> n;
    move(n, 'A', 'B', 'C');

    return 0;
}