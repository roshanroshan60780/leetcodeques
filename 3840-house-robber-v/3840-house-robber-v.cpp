class Solution {
private:
    long long func(int i , int last, vector<int>& nums, vector<int>& colors,vector<vector<long long>>& dp){
        if(i<0) return 0;
        if(dp[i][last]!=-1) return dp[i][last];
        if(last && colors[i]==colors[i+1]){
            return dp[i][last] = func(i-1,false,nums,colors,dp);
        }
        return dp[i][last] = max(nums[i]+func(i-1,true,nums,colors,dp),func(i-1,false,nums,colors,dp));
    }
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<vector<long long>>dp(n, vector<long long>(2,-1));
        return func(n-1,false,nums,colors,dp);
    }
};