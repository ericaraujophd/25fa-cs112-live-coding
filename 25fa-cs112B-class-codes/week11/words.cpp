#include <cassert>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> wordSet;
    string word;

    ifstream inputFile("words_alpha.txt");

    assert(inputFile.is_open());

    while (inputFile >> word) {
        wordSet.insert(word);
    }

    cout << "Hello human, type me a word and I will let you know if the word "
            "exists: ";

    cin >> word;

    // for (set<string>::iterator it= wordSet.begin(); it!=wordSet.end(); ++it)
    //     cout << ' ' << *it << endl;

    if (wordSet.find(word) == wordSet.end()) {
        cout << "404\n";
    } else {
        cout << "Found!\n";
    }
    return 0;
}