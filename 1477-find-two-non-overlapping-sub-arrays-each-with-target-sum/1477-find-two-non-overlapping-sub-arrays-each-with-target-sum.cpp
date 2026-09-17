class Solution {
private:
    int solve(vector<pair<int,int>>& v) {
    int n = v.size();
    if (n < 2) return -1;

    int ans = INT_MAX;
    int best = INT_MAX;

    int j = 0;

    for (int i = 0; i < n; i++) {

        // Intervals ending before current interval starts
        while (j < i && v[j].second < v[i].first) {
            int len = v[j].second - v[j].first + 1;
            best = min(best, len);
            j++;
        }

        // Current interval + shortest non-overlapping previous interval
        if (best != INT_MAX) {
            int len = v[i].second - v[i].first + 1;
            ans = min(ans, len + best);
        }
    }

    return ans == INT_MAX ? -1 : ans;
}
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> prefixsum(n);
        prefixsum[0]=arr[0];
        for(int i=1 ; i<n ; i++){
            prefixsum[i]=prefixsum[i-1]+arr[i];
        }
        int l=0,r=0;
        vector<pair<int,int>> subarray;
        while(l<n && r<n){
            int s=abs(prefixsum[r] - prefixsum[l]) + arr[l];
            if(s==target){
                subarray.push_back({l,r});
                r++;
                l++;
            }
            else if(s>target){
                if(l<r) l++;
                else r++;
            }
            else{
                if(l<=r) r++;
                else l++;
            }
        }
        return solve(subarray);
    }
};