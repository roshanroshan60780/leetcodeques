class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int cover=0;
        for(int i=0 ; i<n ;){
            int c=intervals[i][0];
            int d=intervals[i][1];
            i++;
            while(i<n){
                int a=intervals[i][0];
                int b=intervals[i][1];
                int equalbegin=0;
                while(i<n && a==c){
                    a=intervals[i][0];
                    b=intervals[i][1];
                    cover++;
                    i++;
                }
                if(b>d) break;
                else cover++;
                i++;
            }
        }
        return n-cover;
    }
};