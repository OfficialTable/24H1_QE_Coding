#include "WordCounter.h"

// Fill in here
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iterator>
#include "WordCounter.h"
using namespace std;

void WordCounter::InputText(string aText){
    text = aText;
}

int WordCounter::GetWordCount(void){
    int count = 1;
    for (int i=0; i < text.length(); i++){
        if (text[i] == ' ') {
            count++;
        }
    }
    return count;
}

int WordCounter::GetCharacterCount(void){
    int count = 0;
    for (int i=0; i < text.length(); i++){
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.') {
            count++;
        }
    }
    return text.length() - count ;
}

int WordCounter::GetUniqueWordCount(void){
    for (int i=0; i < text.length(); i++){
        if (text[i] == ',' || text[i] == '.'){
            text[i] = ' ';
            }
    }
    stringstream ss(text);
    map<string, int> mp;
    string word;
    while (ss >> word){
        if (!mp.count(word)){
            mp.insert(make_pair(word, 1));
            }
            else{
                mp[word]++;
                }
            }
    return mp.size();
}

int WordCounter::GetWordCount_OneWord(const char * aWord){
    for (int i=0; i < text.length(); i++){
        if (text[i] == ',' || text[i] == '.'){
            text[i] = ' ';
            }
    }
    stringstream ss(text);
    map<string, int> mp;
    string word;
    while (ss >> word){
        if (!mp.count(word)){
                mp.insert(make_pair(word, 1));
                }
            else{
                mp[word]++;
                }
            }
    return mp[aWord];
}