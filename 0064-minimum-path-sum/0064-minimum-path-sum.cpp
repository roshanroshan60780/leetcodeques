class Solution {
private:
    int func(vector<vector<int>>& grid , int i , int j , vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i==m-1 && j==n-1){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right=INT_MAX,down=INT_MAX;
        if(j<n-1)right=grid[i][j+1] + func(grid,i,j+1,dp);
        if(i<m-1)down=grid[i+1][j] + func(grid,i+1,j,dp);
        return dp[i][j] = min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=grid[0][0]+func(grid,0,0,dp);
        return dp[0][0];
    }
};