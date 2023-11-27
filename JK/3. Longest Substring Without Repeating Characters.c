#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int charIndexMap[256]; 
    for (int i = 0; i < 256; i++) {
        charIndexMap[i] = -1; 
    }

    int maxLength = 0;
    int start = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (charIndexMap[ch] >= start) {
            start = charIndexMap[ch] + 1;
        }
        charIndexMap[ch] = i;
        maxLength = (i - start + 1 > maxLength) ? i - start + 1 : maxLength;
    }

    return maxLength;
}   