class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> time(n+1,INT_MAX);
        priority_queue<pair<int, int>, 
               vector<pair<int, int>>, 
               greater<pair<int, int>>> pq;
        pq.push({0,k});
        time[0]=0;
        time[k]=0;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int curr=temp.second;
            int weights=temp.first;
            for(auto nodes : adj[curr]){
                int edgeweight=nodes.second;
                int node=nodes.first;
                if(weights+edgeweight<time[node]){
                    pq.push({weights+edgeweight,node});
                    time[node]=weights+edgeweight;
                }
            }
        }
        int ans=0;
        for(int x : time){
            ans=max(ans,x);
            if(x==INT_MAX) return -1;
        }
        return ans;
    }
};