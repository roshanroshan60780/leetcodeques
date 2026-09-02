class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0 ;i<n ; i++){
            int j=i+1,k=n-1;
            while(j<k){
                int s=nums[i]+nums[j]+nums[k];
                if(s<0) j++;
                else if(s>0) k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int first=nums[i];
                    int sec=nums[j];
                    int third=nums[k];
                    while(i<n && first==nums[i]) i++;
                    i--;
                    if(i==n) break;
                    while(j<n && sec==nums[j]) j++;
                    while(k>0 && third==nums[k]) k--;
                }
            }
        }
        return ans;
    }
};