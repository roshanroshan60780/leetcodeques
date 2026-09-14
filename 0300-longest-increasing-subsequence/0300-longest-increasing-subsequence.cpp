class Solution {
private:
    int func(int i , int j , vector<int>& nums , vector<vector<int>>& dp){
        int last;
        last = (j==nums.size())?INT_MAX:nums[j];
        if(i==0) return (last>nums[0])?1:0;
        if(dp[i][j]!=-1) return dp[i][j];
        int notpick=func(i-1 , j , nums , dp);
        int pick=INT_MIN;
        if(last>nums[i]) pick=1+func(i-1, i , nums , dp);
        return dp[i][j]=max(pick,notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return func(n-1,n,nums,dp);
    }
};