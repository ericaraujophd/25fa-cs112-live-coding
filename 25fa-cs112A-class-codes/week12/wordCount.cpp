#include <fstream>
#include <iostream>
#include <map>
#include <cassert>
#include <string>

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
            it != wordCount.end(); it++)
    {
                if(temp->second < it->second){
                    temp = it;
                }
    }

    cout << "Max words for " << temp->first << ": " << temp->second << " words.\n";

    return 0;
}