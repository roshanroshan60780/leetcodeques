class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        int twice=0;
        int sum=0;
        for(int x : nums){
            mp[x]++;
            if(mp[x]==2) twice=x;
            sum+=x;
        }
        sum-=twice;
        int n=nums.size();
        int expectedSum=n*(n+1)/2;
        return {twice , expectedSum-sum};
    }
};