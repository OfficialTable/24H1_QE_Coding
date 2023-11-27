#include <stdio.h>

int lengthOfLongestSubstring(char *s) {
    int charIndex[128] = {0};  // Assuming ASCII characters, initialize array to store the last index of each character
    int left = 0;
    int res = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        // If the character at the right pointer is already in the sliding window,
        // move the left pointer to the right of the last occurrence of that character.
        if (charIndex[s[right]] > left) {
            left = charIndex[s[right]];
        }

        // Update the last index of the character in the array.
        charIndex[s[right]] = right + 1;

        // Update the length of the longest substring without repeating characters.
        if (right - left + 1 > res) {
            res = right - left + 1;
        }
    }

    return res;
}
