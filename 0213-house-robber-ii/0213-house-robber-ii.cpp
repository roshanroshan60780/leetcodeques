class Solution {
public:
    int func(int i, int flag ,vector<int>& nums ,vector<int>& dp1,vector<int>& dp0){  //flag check whether last element is picked or not
        if(i==0 && !flag) return nums[0];
        if(i==0) return 0;
        if(flag==1 && dp1[i]!=-1) return dp1[i];
        if(flag==0 && dp0[i]!=-1) return dp0[i];
        int pick=nums[i];
        if(i>=2){
            if(i==nums.size()-1) pick=nums[i]+func(i-2,1,nums,dp1,dp0);
            else pick=nums[i]+func(i-2,flag,nums,dp1,dp0);
        }
        int notpick=func(i-1,flag,nums,dp1,dp0);
        if(flag==1) return dp1[i]=max(pick,notpick);
        if(flag==0) return dp0[i]=max(pick,notpick);
        return dp0[i];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp0(n,-1);
        return func(n-1,0,nums,dp1,dp0);
    }
};