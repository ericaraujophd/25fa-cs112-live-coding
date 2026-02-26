#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream fin;
    fin.open("niceFile.txt");
    ofstream fout("niceOutFile.txt");

    assert(fin.is_open());
    assert(fout.is_open());

    string temp;

    while (fin >> temp) {
        // cout << temp << endl;
        fout << temp << " ";
    }

    fin.close();
    fout.close();
    return 0;
}