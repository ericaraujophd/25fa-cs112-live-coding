#include <set>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

int main(){
    set<string> dictionary;
    string word;

    ifstream fin("words_alpha.txt");

    assert(fin.is_open());
    // saving words into dictionary
    while(fin >> word){
        dictionary.insert(word);
    }

    while(true){
        cout << "Give me a word (9 to quit): ";
        cin >> word;

        if(word == "9") return 0;
        set<string>::iterator it = dictionary.find(word);
        if(it != dictionary.end()) {
            cout << "The word " << *it << " exists indeed.\n";
        }
        else{
            cout << "You illiterate creature. Read the dictionary more often.\n";
        }
    }
    
    return 0;
}