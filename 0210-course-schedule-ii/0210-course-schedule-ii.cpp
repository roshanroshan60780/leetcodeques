class Solution {
private:
    void trace(vector<vector<int>>& adj, vector<int>& visited, int curr , int& flag , vector<int>& ans) {
        if (visited[curr]==1){
            flag=1;
            return;
        }
        if (visited[curr]==2)                //visited[curr]=0 : unvisited node
            return;                          //visited[curr]=1 : node under recursion stack
        visited[curr] = 1;                   //visited[curr]=2 : node is completely proces, means all childs are visited
        int s = adj[curr].size();
        for (int i = 0; i < s; i++) {
            trace(adj, visited, adj[curr][i],flag,ans);
            if (flag)
                return;
        }
        visited[curr]=2;
        ans.push_back(curr);
        return;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> ans;
        int flag=0;
        vector<int> visited(numCourses,0);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                trace(adj,visited,i,flag,ans);
            }
            if(flag) return {};
        }
        return ans;
    }
};