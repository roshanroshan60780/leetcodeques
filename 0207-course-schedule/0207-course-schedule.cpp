class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        vector<int> visited(numCourses,0);
        vector<int> toposort;
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i]==0){q.push(i);visited[i]=1;}
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            toposort.push_back(node);
            for(int x : adj[node]){
                indegree[x]--;
                if(indegree[x]==0 && !visited[x]){
                    q.push(x);
                    visited[x]=1;
                }
            }
        }
        return toposort.size()==numCourses;
    }
};