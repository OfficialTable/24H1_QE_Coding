#include <string.h>
#include <stdio.h>

int minInsertions(char *s) {
    int n = strlen(s);
    int dp[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = 2 + (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0);
            } else {
                dp[i][j] = (dp[i + 1][j] > dp[i][j - 1]) ? dp[i + 1][j] : dp[i][j - 1];
            }
        }
    }

    return n - dp[0][n - 1];
}


int main() {
    char testString[] = "abcb";

    int result = minInsertions(testString);
    printf("Minimum insertions needed for '%s' to become a palindrome: %d\n", testString, result);

    return 0;
}


// int main() {
//     char userInput[100]; // Buffer for the user input

//     printf("Enter a string: ");
//     scanf("%99s", userInput); // Read a string from the user

//     int result = minInsertions(userInput);
//     printf("Minimum insertions needed for '%s' to become a palindrome: %d\n", userInput, result);

//     return 0;
// }