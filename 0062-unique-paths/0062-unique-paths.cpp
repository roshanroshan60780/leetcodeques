class Solution {
private:
    int helper(int m , int n , int i,int j, vector<vector<int>> &dp){
        if((i==m-2 && j==n-1) || (i==m-1 && j==n-2)) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int down=0,right=0;
        if(i<m-1) down=helper(m,n,i+1,j,dp);
        if(j<n-1) right=helper(m,n,i,j+1,dp);
        return dp[i][j]=down + right;
    }
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return helper(m,n,0,0,dp);
    }
};