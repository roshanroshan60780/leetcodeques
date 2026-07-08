class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<vector<int>> q;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int s=q.size();
            for(int i=0 ; i<s ; i++){
                vector<int> temp=q.front();
                q.pop();
                int x=temp[0],y=temp[1],d=temp[2];
                if(mat[x][y]) ans[x][y]=d;
                vector<int> row = {x + 1, x, x - 1, x};
                vector<int> col = {y, y + 1, y, y - 1};
                for (int k = 0; k < 4; k++) {
                    int r=row[k],c=col[k];
                    if (r < m && r >= 0 && c < n && c >= 0 && !visited[r][c]) {
                        visited[r][c]=1;
                        q.push({r,c,d+1});
                    }
                
                }
            }
        }
        return ans;
    }
};