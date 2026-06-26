class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums(m+n,0);
        int i=0,j=0,k=0;
        while(m && n){
            if(nums1[i]<=nums2[j]){
                nums[k]=nums1[i];
                k++;
                m--;
                i++;
            }
            else{
                nums[k]=nums2[j];
                k++;
                n--;
                j++;
            }
        }
        while(m){
            nums[k]=nums1[i];
                k++;
                m--;
                i++;
        }
        while(n){
            nums[k]=nums2[j];
                k++;
                n--;
                j++;
        }
        nums1=nums;
    }
};