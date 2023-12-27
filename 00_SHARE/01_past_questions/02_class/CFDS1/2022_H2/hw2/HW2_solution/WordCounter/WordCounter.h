#pragma once

// Fill in here
#include <iostream>
#include <string>
using namespace std;

class WordCounter {
    public:
    void InputText(string aText); // constructor
    int GetWordCount(void); // four different member functions
    int GetCharacterCount(void);
    int GetUniqueWordCount(void);
    int GetWordCount_OneWord(const char * aWord);
    
    protected:
    string text;
};