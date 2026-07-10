class Solution {
private:
    int ans;
    int func(vector<int>& nums, int ind, vector<int>& dp) {
        if (ind >= nums.size() - 1) {
            return 0;
        }
        if (dp[ind] != -1)
            return dp[ind];
        long long minj=INT_MAX;
        for (int i = 1; i <= nums[ind]; i++) {
            if (ind + i > nums.size() - 1)
                break;
            if (dp[ind + i] != -1) minj=min(1LL+dp[ind+i],minj);

            else minj= min(minj , 1LL+func(nums, ind + i, dp));
        }
        return dp[ind]=minj;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0]=func(nums, 0, dp);
        return dp[0];
    }
};