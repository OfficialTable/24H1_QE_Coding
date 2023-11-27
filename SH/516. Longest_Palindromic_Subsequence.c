#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestPalindromeSubseq(const char *s) {
    int n = strlen(s);
    int dp[n][n];
    memset(dp, 0, sizeof(dp)); // Initialize all elements to 0

    for (int left = n - 1; left >= 0; --left) {
        dp[left][left] = 1;

        for (int right = left + 1; right < n; ++right) {
            if (s[left] == s[right]) {
                dp[left][right] = 2 + dp[left + 1][right - 1];
            } else {
                dp[left][right] = max(dp[left + 1][right], dp[left][right - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    char s[] = "your_sample_string_here";
    printf("Length of longest palindromic subsequence: %d\n", longestPalindromeSubseq(s));
    return 0;
}
