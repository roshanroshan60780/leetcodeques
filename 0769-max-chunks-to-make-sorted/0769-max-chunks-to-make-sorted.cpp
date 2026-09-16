class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int currmax=arr[0];
        int currmin=0;
        int sidx=0;
        int ans=0;
        for(int i=0 ; i<n ; i++){
            currmax=max(currmax,arr[i]);
            if(i-sidx == currmax-currmin){
                ans++;
                currmin=currmax+1;
                sidx=i+1;
            }
        }
        return ans;
    }
};