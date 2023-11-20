class Solution {
public:
    int dp[1000][1000];
    int f(int l, int r, string &s) {
        if(l == r) return 1;
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        return dp[l][r] = s[l] == s[r] ? 2 + f(l+1, r-1, s) : max(f(l+1, r, s),f(l, r-1, s));  
    }
        int longestPalindromeSubseq(string s) { 
        memset(dp, -1, sizeof(dp));
        return f(0, s.size()-1, s); 
    }
};