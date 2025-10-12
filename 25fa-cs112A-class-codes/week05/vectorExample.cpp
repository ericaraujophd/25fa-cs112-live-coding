#include <iostream>
#include <vector>

using namespace std;

class Pair{
    private:
        int first;
        int second;
    public:
        Pair(){
            first = second = 0;
        }

        Pair(int a, int b){
            first = a;
            second = b;
        }
        int getFirst() const{
            return first;
        }
        int getSecond() const{
            return second;
        }
        void setFirst(int value){
            first = value;
        }
        void setSecond(int value){
            second = value;
        }
};

ostream &operator<<(ostream &out, const Pair &p){
    out << p.getFirst() << " | " << p.getSecond() << endl;
    return out;
}

int main(){

    // vector <int> vecInt;
    // for(int i=0; i < 100; i++){
    //     vecInt.push_back(i + 3);
    // }

    // for(vector<int>::iterator it = vecInt.begin(); it != vecInt.end(); it++){
    //     cout << *it << ", ";
    // }
    
    vector<Pair> vecPair;
    for(int i=0; i < 5; i++){
        Pair p(i, i+2);
        vecPair.push_back(p);
    }

    for(vector<Pair>::iterator it = vecPair.begin(); it != vecPair.end(); it++){
        cout << *it << ", ";
    }

    return 0;
}
