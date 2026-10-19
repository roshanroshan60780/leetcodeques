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
    bool isUltimateparent(int i){
        return i==parent[i];
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int links=0;  //maxm no. of links we can break;
        DisjointSet ds(n);
        for(auto it : connections){
            if(ds.find(it[0],it[1])){
                links++;
                continue;
            }
            ds.unionByRank(it[0],it[1]);
        }
        int components=-1;
        for(int i=0 ; i<n ; i++){
            if(ds.isUltimateparent(i)) components++;
        }
        if(components>links) return -1;
        return components;
    }
};