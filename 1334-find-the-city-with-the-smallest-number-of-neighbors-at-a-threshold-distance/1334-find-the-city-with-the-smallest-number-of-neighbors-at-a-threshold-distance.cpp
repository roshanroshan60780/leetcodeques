class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e8));
        for(int i=0 ; i<n ; i++) matrix[i][i]=0;
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            matrix[u][v]=w;
            matrix[v][u]=w;
        }
        for(int via=0 ; via<n ; via++){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    int x=1e8;
                    if(matrix[i][via]!=1e8 && matrix[via][j]!=1e8) x=matrix[i][via]+matrix[via][j];
                    if(matrix[i][via]!=1e8 && matrix[via][j]!=1e8 && x<matrix[i][j]) matrix[i][j]=x;
                }
            }
        }
        int ans=-1;
        int last=n-1;
        for(int i=0 ; i<n ; i++){
            int curr=0;
            for(int j=0 ; j<n ; j++){
                if(i!=j && distanceThreshold>=matrix[i][j]) curr++;
            }
            if(curr<=last){
                ans=i;
                last=curr;
            }
        }
        return ans;
    }
};