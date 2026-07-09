class Solution {
private:
    bool check(vector<vector<int>>& graph ,vector<int> &coloured, int node, int colour){
        coloured[node]=colour;
        for(auto it : graph[node]){
            if(coloured[it]==-1){
                if(!check(graph,coloured,it,!colour)) return false;
            }
            else if(coloured[it]==colour) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> coloured(n,-1);
        for(int i=0 ; i<n ; i++){
            if(coloured[i]==-1){
                if(!check(graph,coloured,i,0)) return false;
            }
        }
        return true;
    }
};