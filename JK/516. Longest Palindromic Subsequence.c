#include <stdio.h>
#include <string.h>

int longestPalindromeSubseq(char *s) {
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
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = (dp[i + 1][j] > dp[i][j - 1]) ? dp[i + 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[0][n - 1];
}


int main() {
    char str[] = "bbbab";
    printf("The length of the longest palindromic subsequence is: %d\n", longestPalindromeSubseq(str));
    return 0;
}

// 사용자 입력으로 테스트하는 main 함수
// int main() {
//     char str[1000];
//     printf("Enter a string: ");
//     scanf("%999s", str);
//     printf("The length of the longest palindromic subsequence is: %d\n", longestPalindromeSubseq(str));
//     return 0;
// }