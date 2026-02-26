#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("stupidfile.txt");
    assert(fin.is_open());

    string str;

    // while (fin >> str) {
    //     cout << str << endl;
    // }

    while(getline(fin, str)){

        cout << str << endl;
    }

    return 0;
}