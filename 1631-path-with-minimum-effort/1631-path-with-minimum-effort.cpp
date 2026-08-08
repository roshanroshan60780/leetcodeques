class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        if(rows==1 && cols==1) return 0;
        vector<vector<int>> effort(rows,vector<int>(cols,INT_MAX));
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0,0,0});
        effort[0][0]=0;
        int ans=INT_MIN;
        while(!pq.empty()){
            auto[w,r,c] = pq.top();
            pq.pop();
            int delr[4]={r,r+1,r,r-1};
            int delc[4]={c+1,c,c-1,c};
            for(int i=0 ; i<4 ; i++){
                if(delr[i]<0 || delc[i]<0 || delr[i]>=rows || delc[i]>=cols) continue;
                int neweff=max(abs(heights[r][c]-heights[delr[i]][delc[i]]),w);
                if(effort[delr[i]][delc[i]] > neweff){
                    effort[delr[i]][delc[i]] = neweff;
                    pq.push({neweff,delr[i],delc[i]});
                }
            }
        }
        return effort[rows-1][cols-1];
    }
};