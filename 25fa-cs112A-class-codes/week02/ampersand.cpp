#include <iostream>

using namespace std;


void age(int *previousAge){
    (*previousAge)++;
    cout << *previousAge << endl;
}

void age2(int &previousAge){
    previousAge++;
}

int main(){

    int pA = 17;
    age(&pA);
    cout << "pA: " << pA << endl;
    age2(pA);
    cout << "pA after 2: " << pA << endl;
}