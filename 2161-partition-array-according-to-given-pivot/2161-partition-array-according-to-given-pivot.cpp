class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int cntpivot=0;
        vector<int> greater;
        for(int x:nums){
            if(x<pivot) ans.push_back(x);
            if(x==pivot) cntpivot++;
            if(x>pivot) greater.push_back(x);
        }
        while(cntpivot){
            ans.push_back(pivot);
            cntpivot--;
        }
        ans.insert(ans.end(),greater.begin(),greater.end());
        return ans;
    }
};