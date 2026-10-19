class DisjointSet {
private:
    vector<int> parent;
    vector<int> rankValue;
 
public:
    // Initializes one independent set for every node.
    DisjointSet(int n) {
        parent.resize(n + 1);
        rankValue.assign(n + 1, 0);
 
        // Make every node its own parent.
        for (int node = 1; node <= n; node++) {
            parent[node] = node;
        }
    }
 
    // Returns the representative using path compression.
    int findParent(int node) {
        // Base case: node is its own representative.
        if (parent[node] == node) {
            return node;
        }
 
        // Compress the path while finding the representative.
        parent[node] = findParent(parent[node]);
 
        return parent[node];
    }
 
    // Merges two sets using rank balancing.
    void unionByRank(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
 
        // Same representative means both nodes are already connected.
        if (rootU == rootV) {
            return;
        }
 
        // Keep the higher-rank root as the parent.
        if (rankValue[rootU] < rankValue[rootV]) {
            swap(rootU, rootV);
        }
 
        // Attach the lower-rank root to the higher-rank root.
        parent[rootV] = rootU;
 
        // Increase rank only when both ranks are equal.
        if (rankValue[rootU] == rankValue[rootV]) {
            rankValue[rootU]++;
        }
    }
 
    // Checks whether two nodes share one set.
    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(isConnected[i][j]==1){
                    ds.unionByRank(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0 ; i<n ; i++){
            if(ds.findParent(i)==i) cnt++;
        }
        return cnt;
    }
};