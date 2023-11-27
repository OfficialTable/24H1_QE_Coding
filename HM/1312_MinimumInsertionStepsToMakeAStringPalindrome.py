#Longest Palindromic Subsequence를 찾아서 그거를 전체 길이에서 빼주면 끝! 매우쉽다.
def minInsertions(s):
        """
        :type s: str
        :rtype: int
        """
            
        def longestPalindromeSubseq(s):
            s2 = s[::-1]
            #[row[col]] = [s[s2]]
            dp = [[0 for j in range(len(s2)+1)]for i in range(len(s)+1)] 

            for i in range(len(s) -1, -1, -1):
                for j in range(len(s2) -1, -1, -1):
                    if s[i] == s2[j]:
                        dp[i][j] = 1 + dp[i+1][j+1] #diagnoal에 1을 더해주기
                    else:
                        dp[i][j] = max(dp[i][j+1], dp[i+1][j]) #matching 하지 않으면 오른쪽이나 밑에 값 중 더 큰 것을 가져오기

            return dp[0][0]
        
        lengthLongestPalindrome = longestPalindromeSubseq(s)
        # 최소 삽입 횟수는 전체 길이에서 최장 회문 부분 수열의 길이를 뺀 값
        min_insertions = len(s) - lengthLongestPalindrome
        return min_insertions