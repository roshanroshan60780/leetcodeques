class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int size=nums.size();
        for(int i=0 ; i<size ; i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=i;
            }
            else{
                int previdx=mp[nums[i]];
                mp[nums[i]]=i;
                if(i-previdx <=k) return true;
            }
        }
        return false;
    }
};