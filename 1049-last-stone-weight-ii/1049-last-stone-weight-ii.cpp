class Solution {
private:
    int func(int i ,int target, vector<int>& stones , vector<vector<int>>& dp){
        if(target==0) return dp[i][target] = true;
        if(i==0) return dp[i][target]=stones[i]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        int notpick=func(i-1,target,stones,dp);
        int pick=0;
        if(stones[i]<=target) pick=func(i-1,target-stones[i],stones,dp);
        return dp[i][target]=pick | notpick;
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size(),sum=0;
        for(int x:stones) sum+=x;
        vector<vector<bool>> dp(n,vector<bool>(sum/2+1,false));
        for(int i=0 ; i<n ; i++) dp[i][0]=true;
        if(stones[0]<=sum/2+1) dp[0][stones[0]]=true;
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<sum/2+1 ; j++){
                bool notpick=dp[i-1][j];
                bool pick=0;
                if(stones[i]<=j) pick=dp[i-1][j-stones[i]];
                dp[i][j]=pick || notpick;
            }
        }
        int ans=1e9;
        for(int j=0 ; j<sum/2+1 ; j++){
            if(dp[n-1][j]) ans=min(ans,abs(sum-2*j));
        }
        return ans;
    }
};