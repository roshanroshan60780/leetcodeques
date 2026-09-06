class Solution {
private:
    bool func(int i , int sum , vector<int>& arr , vector<vector<int>>& dp){
        if(sum==0) return true;
        if(sum<0) return false;
        if(i==arr.size()) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool pick=func(i+1,sum-arr[i],arr,dp);
        bool notpick=func(i+1,sum,arr,dp);
        return dp[i][sum]=pick || notpick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0 ; i<n ; i++) sum+=nums[i];
        if(sum%2) return false;
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return func(0,sum/2,nums,dp);
    }
};