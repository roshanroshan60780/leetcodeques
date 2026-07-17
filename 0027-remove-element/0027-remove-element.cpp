class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0) return 0;
        int k=0;
        int i=0 , j=n-1;
        while(j>=0 && nums[j]==val) j--;
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
                k++;

            }
            else k++;
            i++;
            while(j>=0 && nums[j]==val) j--;
        }
        return k;
    }
};