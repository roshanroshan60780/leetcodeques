class Solution {
private:
    int func(int i, int j1 , int j2,vector<vector<int>>& grid , vector<vector<vector<int>>>& dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=INT_MIN;
        int curr=grid[i][j1];
        if(j1!=j2) curr+=grid[i][j2];
        for(int a=-1 ; a<=1 ; a++){
            if(j1+a<0 || j1+a>=m) continue;
            for(int b=-1 ; b<=1 ; b++){
                if(j2+b>=0 && j2+b<m){
                    ans=max(ans,curr+func(i+1,j1+a,j2+b,grid,dp));
                }
            }
        }
        return dp[i][j1][j2]= ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return func(0,0,m-1,grid,dp);
    }
};