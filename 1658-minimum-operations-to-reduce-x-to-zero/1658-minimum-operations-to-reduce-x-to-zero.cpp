class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(int x:nums) sum+=x;
        int target=sum-x;
        if(target<0) return -1;
        if(target==0) return n;
        int maxlen=0;
        int i=0,j=0;
        int curr=nums[0];
        while(j<n){
            if(curr==target){
                maxlen=max(maxlen,j-i+1);
                curr-=nums[i];
                i++;j++;
                curr+=nums[j];
            }
            else if(curr<target){
                j++;
                if(j<n) curr+=nums[j];
            }
            else{
                curr-=nums[i];
                i++;
            }
        }
        if(maxlen==0) return -1;
        return n-maxlen;
    }
};