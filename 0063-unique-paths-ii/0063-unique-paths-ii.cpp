class Solution {
private:
    int helper(int m , int n , int i,int j, vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
        if(i==m-1 && j==n-1) return 0;
        if(obstacleGrid[i][j]) return dp[i][j]=0;
        if(dp[i][j] != -1) return dp[i][j];
        int down=0,right=0;
        if(i<m-1) down=helper(m,n,i+1,j,dp,obstacleGrid);
        if(j<n-1) right=helper(m,n,i,j+1,dp,obstacleGrid);
        return dp[i][j]=down + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]) return 0;
        vector<vector<int>> dp(m , vector<int>(n,-1));
        if(n==1 && m==1) return 1;
        if(n>=2)dp[m-1][n-2]=(obstacleGrid[m-1][n-2])?0:1;
        if(m>=2)dp[m-2][n-1]=(obstacleGrid[m-2][n-1])?0:1;
        return helper(m,n,0,0,dp,obstacleGrid);
    }
};