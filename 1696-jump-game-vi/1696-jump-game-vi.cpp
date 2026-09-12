class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,-1);
        priority_queue<pair<int,int>> pq;
        dp[0]=nums[0];
        pq.push({dp[0],0});
        for(int i=1 ;i<n ; i++){
            int lower=max(0,i-k);
            int upper=i-1;
            auto temp=pq.top();
            while(temp.second<lower || temp.second>upper){
                pq.pop();
                temp=pq.top();
            }
            dp[i]=dp[temp.second] + nums[i];
            pq.push({dp[i],i});
        }
        return dp[n-1];
    }
};