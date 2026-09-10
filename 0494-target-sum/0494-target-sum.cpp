class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0 ; i<n ; i++) sum+=nums[i];
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int i=0 ; i<n ; i++) dp[i][0]=1;
        if(nums[0]<=sum && nums[0]==0)dp[0][nums[0]]=2;
        else if(nums[0]<=sum) dp[0][nums[0]]=1;
        for(int i=1; i<n ; i++){
            for(int j=0; j<sum+1 ; j++){
                int notpick=dp[i-1][j];
                int pick=0;
                if(nums[i]<=j) pick=dp[i-1][j-nums[i]];
                dp[i][j]=pick + notpick;
            }
        }
        int ans=0;
        for(int i=0; i<sum+1 ; i++){
            if(dp[n-1][i]){
                if(2*i - sum == abs(target)) ans+=dp[n-1][i];
            }
        }
        return ans;
    }
};