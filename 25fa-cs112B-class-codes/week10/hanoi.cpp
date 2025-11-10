#include <iostream> 

using namespace std;

void move(int numDisks, char src, char dst, char aux){
    cout << "---- " << numDisks << " --------" << endl;
    if(numDisks == 1){
        cout << "Move " << src << " to " << dst << endl;
    }
    else{
        move(numDisks - 1, src, aux, dst);
        move(1, src, dst, aux);
        move (numDisks - 1, aux, dst, src);
    }
}

int main(){
    move(64, 'A', 'B', 'C');
    return 0;
}