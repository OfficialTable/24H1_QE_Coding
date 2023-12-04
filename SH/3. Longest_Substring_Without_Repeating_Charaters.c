#include <unordered_map>
#include <string>

// Answer
int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLongestSubstring(char* s) {
    int memo[256] = {0}; // For all occurence of characters
    int l = 0; // left pointer
    int r = 0; // right pointer
    int count = 0; // initializing 

    while(r<strlen(s)){ // can use .length (for C++) or strlen()
        memo[s[r]]++;
        while(memo[s[r]]>1){ // For repeated character
            memo[s[l]]--;
            l++;
        }
        count = max(count, r-l+1);
        r++;
    }
    return count;
}

// Direct translation from python file
// Not properly worked in Leetcode
int lengthOfLongestSubstring(char* s) {
    unordered_map<string, int> memo;
    int count = 0;
    int pointer = 0;
    for(int i=0;i<strlen(s);i++){
        // Sliding window by moving the pointer
        if memo.find(s[i]) != memo.end(){
            count = max(count, i-pointer+1);
        }
        // If s[i] already seen
        else{
            if(memo.find(s[i]) < pointer){
                count = max(count, i-pointer+1);
            }
            else{
                pointer = memo.find(s[i]) + 1
            }
        memo.insert(make_pair(s[i], i))
        }
    }
    return count;
}

