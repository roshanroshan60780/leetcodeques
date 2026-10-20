class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int composize(int node){
        return size[node];
    }
};
class Solution {
private:
    bool isvalid(int r, int c, int n){
        return r>=0 && c>=0 && r<n && c<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==0) continue;
                vector<int> nr={i,i+1,i,i-1};
                vector<int> nc={j+1 , j , j-1, j};
                for(int k=0 ; k<4 ; k++){
                    int r=nr[k], c=nc[k];
                    if(isvalid(r,c,n) && grid[r][c]==1){
                        ds.unionBySize(i*n+j,r*n+c);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==1) continue;
                vector<int> nr={i,i+1,i,i-1};
                vector<int> nc={j+1 , j , j-1, j};
                set<int> s;
                for(int k=0 ; k<4 ; k++){
                    int r=nr[k], c=nc[k];
                    if(isvalid(r,c,n) && grid[r][c]==1){
                        s.insert(ds.findUPar(r*n + c));
                    }
                }
                int temp=0;
                for(int it : s){
                    int up=ds.findUPar(it);
                    temp+=ds.composize(up);
                }
                ans=max(ans,temp+1);
            }
        }
        if(ans==0) return ds.composize(ds.findUPar(0));
        return ans;
    }
};