class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n];
        for(auto flight : flights){
            graph[flight[0]].push_back({flight[1],flight[2]});
        }
        vector<int> price(n,INT_MAX);
        vector<int> stops(n,0);
        queue<pair<int,pair<int,int>>> q;
        price[src]=0;
        q.push({0,{src,0}}); //{price,{stop,no.of stops}}
        while(!q.empty()){
            pair<int,pair<int,int>> curr=q.front();
            q.pop();
            int currprice=curr.first;
            int currstop=curr.second.first;
            int nstops=curr.second.second;
            if(nstops>=k+1 || currstop==dst) continue;
            for(auto stop : graph[currstop]){
                int nxtstop=stop.first;
                int nxtprice=stop.second;
                if(currprice + nxtprice<price[nxtstop] && nstops<=k){
                    q.push({currprice + nxtprice,{nxtstop,nstops+1}});
                    price[nxtstop]=currprice + nxtprice;
                }
            }
        }
        if(price[dst]==INT_MAX) return -1;
        return price[dst];
    }
};