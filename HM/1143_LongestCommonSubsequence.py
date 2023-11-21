def longestCommonSubsequence(text1: str, text2: str) -> int:
    #[row[col]] = [text1[text2]]
    dp = [[0 for j in range(len(text2)+1)]for i in range(len(text1)+1)] 

    for i in range(len(text1) -1, -1, -1):
        for j in range(len(text2) -1, -1, -1):
            if text1[i] == text2[j]:
                dp[i][j] = 1 + dp[i+1][j+1] #diagnoal에 1을 더해주기
            else:
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]) #matching 하지 않으면 오른쪽이나 밑에 값 중 더 큰 것을 가져오기

    return dp[0][0]
