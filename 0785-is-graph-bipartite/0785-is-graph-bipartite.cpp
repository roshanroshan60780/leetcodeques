class Solution {
private:
    bool check(vector<vector<int>>& graph , int curr, vector<int> &coloured){
        
        queue<int> q;
        q.push(curr);
        coloured[curr]=1;
        int col=2;
        while(!q.empty()){
            int size=q.size();
            for(int i=0 ; i<size ; i++){
                int node=q.front();
                q.pop();
                int s=graph[node].size();
                for(int j=0 ; j<s ; j++){
                    if(!coloured[graph[node][j]]){
                        q.push(graph[node][j]);
                        coloured[graph[node][j]]=col;
                    }
                    else if(coloured[graph[node][j]]!=col) return false;
                }
            }
            col = (col==1)? 2 : 1;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> coloured(n);
        for(int i=0 ; i<n ; i++){
            if(!coloured[i]){
                if(!check(graph,i,coloured)) return false;
            }
        }
        return true;
    }
};