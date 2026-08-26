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
        vector<vector<int>>dp(n, vector<int>(n,-100000));
        return func(0,0,triangle,dp);
    }
};