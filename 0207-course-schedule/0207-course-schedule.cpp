class Solution {
private:
    bool detect(vector<vector<int>>& adj, vector<int>& visited, int curr) {
        if (visited[curr]==1)
            return false;
        if (visited[curr]==2)                //visited[curr]=0 : unvisited node
            return true;                     //visited[curr]=1 : node under recursion stack
        visited[curr] = 1;                   //visited[curr]=2 : node is completely proces, means all childs are visited
        int s = adj[curr].size();
        bool ans = true;
        for (int i = 0; i < s; i++) {
            ans = ans && detect(adj, visited, adj[curr][i]);
            if (!ans)
                return false;
        }
        visited[curr]=2;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses,0);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!detect(adj, visited, i))
                    return false;
            }
        }
        return true;
    }
};