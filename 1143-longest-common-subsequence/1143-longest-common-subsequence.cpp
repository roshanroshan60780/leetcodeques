class Solution {
private:
    int func(int i, int j, string& text1, string& text2,
             vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i] == text2[j])
            return dp[i][j] = 1 + func(i - 1, j - 1, text1, text2, dp);
        return dp[i][j] = 0 + max(func(i - 1, j, text1, text2, dp),
                                  func(i, j - 1, text1, text2, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (text1[i] == text2[j])
                    dp[i+1][j+1] = 1 + dp[i][j];
                else
                    dp[i+1][j+1] = 0 + max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[n1][n2];
    }
};