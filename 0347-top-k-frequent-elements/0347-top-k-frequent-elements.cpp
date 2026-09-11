class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto temp : mp){
            if(pq.size()<k){
                pq.push({temp.second,temp.first});
            }
            else{
                pq.push({temp.second,temp.first});
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};