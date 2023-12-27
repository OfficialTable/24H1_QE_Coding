#include "wordcount.h"
#include <iostream>
#include <sstream>

#define MAX_WORDS 30

void wordcount(std::string sentences) {
    // store number of total words
    unsigned int total_words = 0;

    // TODO: calculate word counts
    std::stringstream stream(sentences);
    std::string word;

    while (stream >> word) {
//        std::cout<<word<<std::endl;
        total_words++;
    }

    std::cout << "Total number of words: " << total_words << std::endl;

    // Error message for a sentence that is more than MAX_WORDS
    if (total_words > MAX_WORDS) {
        std::cout << "Error: Given string is too long! The string should be less than " << MAX_WORDS + 1 << " words." << std::endl;
        return;
    }

    // TODO: print number of appearances for each word

    std::stringstream stream2(sentences);

    // 1. make bucket for word&count
    std::string word_array[MAX_WORDS] = {};
    int cnt_array[MAX_WORDS] = {};
    int idx = 0; // # of unique words

    // 2. count
    while (stream2 >> word) {
        bool existing = false;
        int idx_tmp = 0;
        // check if word is already in word_array
        if (idx > 1) {
            for (int i = 0; i < idx; i++) {
                //              std::cout << i<< " " << word << word_array[i]<<std::endl;
                if (word == word_array[i]) {
                    existing = true;
                    idx_tmp = i;
//                    std::cout << existing << " " << idx_tmp << std::endl;
                }
//                std::cout << "test: " << i << std::endl;
            }
        }
        // Not existing 
        if (existing == false) {
            word_array[idx] = word;
            cnt_array[idx]++;
            idx++;
        }
        // existing
        else {
            cnt_array[idx_tmp]++;
        }
    }

    // 3. Print(cout)
    for (int i = 0; i < idx; i++) {
        // 1 -> once
        if (cnt_array[i] == 1) {
            std::cout << "Word \"" << word_array[i] << "\" appears once." << std::endl;
        }
        // 2-> twice
        else if (cnt_array[i] == 2) {
            std::cout << "Word \"" << word_array[i] << "\" appears twice." << std::endl;
        }
        // others
        else {
            std::cout << "Word \"" << word_array[i] << "\" appears " << cnt_array[i] << " times." << std::endl;
        }
    }
}
