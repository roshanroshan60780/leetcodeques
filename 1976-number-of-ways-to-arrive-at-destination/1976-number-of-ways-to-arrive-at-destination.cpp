class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long, int>, 
               vector<pair<long long, int>>, 
               greater<pair<long long, int>>> pq;
        vector<long long> time(n,LLONG_MAX);
        vector<long long> ways(n,0);
        pq.push({0,0});
        time[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            long long weight=curr.first;
            int node=curr.second;
            for(auto it : adj[node]){
                long long edgeweight=it.second;
                int child=it.first;
                if(edgeweight+weight==time[child]){
                    ways[child]=(ways[child]+ways[node])%MOD;
                }
                else if(edgeweight+weight<time[child]){
                    pq.push({edgeweight+weight,child});
                    time[child]=edgeweight+weight;
                    ways[child]=ways[node];
                }
            }
        }
        return ways[n-1]%MOD;
    }
};