#include <fstream>
#include <cassert>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
    map<string,int> wordCount;
    string word;

    ifstream fin("stve.txt");

    assert(fin.is_open());

    while(fin >> word){
        wordCount[word]++;
    }

    map<string,int>::iterator temp = wordCount.begin();

    for(map<string,int>::iterator it = wordCount.begin();
        it != wordCount.end(); it++
    ){
        if(temp->second >= it->second){
            temp = it;
        }
    }

    cout << "The word with the highest number of appearences is: \'" << temp->first << "\' = " << temp->second << " times.\n"; 

    return 0;
}