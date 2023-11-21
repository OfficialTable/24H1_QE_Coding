#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n <= 1) {
        return strdup(s);
    }

    bool dp[MAX_LENGTH][MAX_LENGTH] = {false};
    int start = 0, max_length = 1;

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                if (length == 2 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (length > max_length) {
                        start = i;
                        max_length = length;
                    }
                }
            }
        }
    }

    char* result = (char*)malloc(max_length + 1);
    strncpy(result, s + start, max_length);
    result[max_length] = '\0';
    return result;
}


int main() {
    char str[] = "babad";
    char* result = longestPalindrome(str);
    printf("The longest palindromic substring is: %s\n", result);
    free(result);
    return 0;
}

//사용자 입력을 받아서 테스트
// int main() {
//     char str[MAX_LENGTH];
//     printf("Enter a string: ");
//     scanf("%999s", str);
//     char* result = longestPalindrome(str);
//     printf("The longest palindromic substring is: %s\n", result);
//     free(result);
//     return 0;
// }