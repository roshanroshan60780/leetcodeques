class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0 ; int j=0;
        int s1=nums1.size(),s2=nums2.size();
        vector<int> ans;
        while(i<s1 && j<s2){
            while(i<s1 && nums1[i]<nums2[j]) i++;
            while(i<s1 && j<s2 && nums1[i]>nums2[j]) j++;
            while(i<s1 && j<s2 && nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};