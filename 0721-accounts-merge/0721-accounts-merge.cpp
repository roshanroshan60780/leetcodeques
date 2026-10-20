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
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mp1;
        DisjointSet ds(n);
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<accounts[i].size() ; j++){
                string mail=accounts[i][j];
                if(mp1.find(mail)==mp1.end()){
                    mp1[mail]=i;
                }
                else{
                    ds.unionBySize(i,mp1[mail]);
                    mp1[mail];
                }
            }
        }
        vector<string> vec[n];    // stores merged mail;
        for(auto it : mp1){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            vec[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0 ; i<n ; i++){
            if(vec[i].size()!=0){
                sort(vec[i].begin(),vec[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto mail:vec[i]){
                    temp.push_back(mail);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};