class Solution {
private:
    bool detect(vector<vector<int>>& adj, vector<int>& visited, int curr,
                unordered_set<int>& path) {
        if (path.count(curr))
            return false;
        if (visited[curr])
            return true;
        visited[curr] = 1;
        int s = adj[curr].size();
        bool ans = true;
        path.insert(curr);
        for (int i = 0; i < s; i++) {
            ans = ans && detect(adj, visited, adj[curr][i], path);
            if (!ans)
                return false;
        }
        path.erase(curr);
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> path;
        vector<int> visited(numCourses,0);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!detect(adj, visited, i, path))
                    return false;
            }
        }
        return true;
    }
};