class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int i=0;
        int n=points.size();
        int ans=0;
        while(i<n){
            int temp=points[i][1];
            while(i<n && temp>=points[i][0]) i++;
            ans++;
        }
        return ans;
    }
};