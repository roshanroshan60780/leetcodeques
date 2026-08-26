class Solution {
private:
    int func(int i, int level , vector<vector<int>>& triangle , vector<vector<int>>& dp){
        int n=triangle.size();
        if(level==n-1) return triangle[level][i];
        if(i>level) return 1e8;
        if(dp[level][i]!=-100000) return dp[level][i];
        int temp1=func(i,level+1,triangle,dp);
        int temp2=func(i+1,level+1,triangle,dp);
        return dp[level][i] = min(temp1,temp2) + triangle[level][i];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n));
        dp[0][0]=triangle[0][0];
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<=i ; j++){
                if(j==0){
                    dp[i][j]=triangle[i][j]+dp[i-1][j];
                }
                else if(j==i){
                    dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0 ; i<n ; i++){
            if(dp[n-1][i]<ans) ans=dp[n-1][i];
        }
        return ans;
    }
};