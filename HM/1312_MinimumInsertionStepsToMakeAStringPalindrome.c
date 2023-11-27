#python과 동일하게 longest palindromic subsequence의 길이를 찾아서 string length에서 빼준다.

int minInsertions(char* s) {
    int lengthLongestPalindrome = longestPalindromeSubseq(s);
    // 최소 삽입 횟수는 전체 길이에서 최장 회문 부분 수열의 길이를 뺀 값
    int min_insertions = strlen(s) - lengthLongestPalindrome;
    return min_insertions;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestPalindromeSubseq(char* s) {
    int n = strlen(s);
    char s2[n + 1];
    
    // Reverse the string s
    for (int i = 0; i < n; ++i) {
        s2[i] = s[n - 1 - i];
    }
    s2[n] = '\0';  // Null-terminate the reversed string
    
    // Create a 2D array for dynamic programming
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp array using dynamic programming
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i] == s2[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][0];
}
