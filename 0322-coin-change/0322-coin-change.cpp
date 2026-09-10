class Solution {
private:
    int func(int i , int amt , vector<int>& coins , vector<vector<int>>& dp){
        if(amt==0) return 0;
        if(i<0) return 1e9;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int nottake=func(i-1,amt,coins,dp);
        int take=INT_MAX;
        if(coins[i]<=amt) take=1 + func(i,amt-coins[i],coins,dp);
        return dp[i][amt]=min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0) return 0;
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=func(n-1,amount,coins,dp);
        if(ans>=1e9 && amount!=0) return -1;
        return ans;
    }
};