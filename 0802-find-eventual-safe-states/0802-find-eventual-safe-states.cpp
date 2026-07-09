class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> terminal;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int s = graph[i].size();
            if (s == 0) {
                terminal.push_back(i);
                continue;
            }
            for (int j = 0; j < s; j++) {
                rev[graph[i][j]].push_back(i);
            }
        }
        if (terminal.empty())
            return {};
        queue<int> q;
        vector<int> visited(n);
        for (auto it : terminal) {
            q.push(it);
            st.insert(it);
            visited[it] = 1;
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                for (int it : rev[node]) {
                    if (!visited[it]) {
                        int flag = 1;
                        for (int x : graph[it]) {
                            if (st.find(x) == st.end()) {
                                flag = 0;
                                break;
                            }
                        }
                        if (flag) {
                            q.push(it);
                            visited[it] = 1;
                            st.insert(it);
                            terminal.push_back(it);
                        }
                    }
                }
            }
        }
        sort(terminal.begin(),terminal.end());
        return terminal;
    }
};