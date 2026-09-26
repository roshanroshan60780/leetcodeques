class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long sum=0;
        for(int x:nums){
            sum+=x;
        }
        int rem=sum%p;
        if(rem==0) return 0;
        unordered_map<int,int> mp;
        long long prevsum=0;
        int ans=n;
        for(int i=0 ;i<n ; i++){
            prevsum+=nums[i];
            int curr=prevsum%p;
            int prevrem=(curr-rem+p)%p;
            if(prevrem==0) ans=min(i+1,ans);
            if(mp.find(prevrem)!=mp.end()){
                ans=min(i-mp[prevrem],ans);
            }
            mp[curr]=i;
        }
        if(ans==n) return -1;
        return ans;
    }
};