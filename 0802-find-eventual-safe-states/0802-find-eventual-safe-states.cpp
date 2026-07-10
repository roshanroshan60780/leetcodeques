class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        queue<int> q;
        vector<int> indegree(n);
        vector<int> visited(n);
        for (int i = 0; i < n; i++) {
            int s = graph[i].size();
            indegree[i]=s;
            if (s == 0) {
                q.push(i);
                visited[i]=1;
            }
            for (int j = 0; j < s; j++) {
                rev[graph[i][j]].push_back(i);
            }
        }
        vector<int>  safenode;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenode.push_back(node);
            for(int x : rev[node]){
                indegree[x]--;
                if(indegree[x]==0 && !visited[x]){
                    q.push(x);
                    visited[x]=1;
                }
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
    }
};