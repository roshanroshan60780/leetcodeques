class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0 ; i<n+1 ; i++){
            int num=i;
            while(num){
                ans[i]+=num & 1;
                num=num>>1;
            }
        }
        return ans;
    }
};