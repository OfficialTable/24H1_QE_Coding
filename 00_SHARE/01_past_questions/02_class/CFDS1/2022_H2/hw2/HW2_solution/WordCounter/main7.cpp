#include <iostream>
#include <string>
#include "WordCounter.h"
using namespace std;

int main() {
  
  	string text = "thisisaverylongword.";
	WordCounter counter;
	counter.InputText(text);
	
	cout << "Word Count: " << counter.GetWordCount() << endl;
	cout << "Character Count: " << counter.GetCharacterCount() << endl;
	cout << "Number of Unique Words: " << counter.GetUniqueWordCount() << endl;
 	cout << "The word and appears " << counter.GetWordCount_OneWord("is") << " times" << endl;
 	
 	return 0;
}