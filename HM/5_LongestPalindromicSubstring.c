#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int start = 0, end = 0;
    int resLen = 0;
    int len = strlen(s);

    for (int i = 0; i < len; ++i) {
        // odd length, e.g., "bab"
        int left1 = i, right1 = i;
        while (left1 >= 0 && right1 < len && s[left1] == s[right1]) {
            if (right1 - left1 + 1 > resLen) {
                start = left1;
                end = right1;
                resLen = right1 - left1 + 1;
            }
            left1--;
            right1++;
        }

        // even length, e.g., "cbbc"
        int left2 = i, right2 = i + 1;
        while (left2 >= 0 && right2 < len && s[left2] == s[right2]) {
            if (right2 - left2 + 1 > resLen) {
                start = left2;
                end = right2;
                resLen = right2 - left2 + 1;
            }
            left2--;
            right2++;
        }
    }

    char* result = (char*)malloc((resLen + 1) * sizeof(char));
    strncpy(result, s + start, resLen);
    result[resLen] = '\0';

    return result;
}