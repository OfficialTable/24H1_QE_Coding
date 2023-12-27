#include <iostream>
#include <string>
#include <fstream>
#include "WordCounter.h"
using namespace std;

int main() {
  
  	string text = "";
	string word = "";
	WordCounter counter;
	// Open the input file
	ifstream input_file("./input.txt");
	ifstream word_file("./word.txt");
	ofstream output_file("./output.txt");

	//Read the text 
	while (getline(input_file, text) && getline(word_file, word)) {
		counter.InputText(text);
		const char* cstr = word.c_str();
		// cout << word << endl;

		output_file << "Word Count: " << counter.GetWordCount() << endl;
		output_file << "Character Count: " << counter.GetCharacterCount() << endl;
		output_file << "Number of Unique Words: " << counter.GetUniqueWordCount() << endl;
		output_file << "The word appears " << counter.GetWordCount_OneWord(cstr) << " times" << endl;
	}

	// Close the input file
	input_file.close();
	word_file.close();
	// Close the output file
 	output_file.close();

 	return 0;
}