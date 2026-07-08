class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n));
        for(int i=0 ; i<n ; i++){
            if(grid[0][i]==1){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(grid[m-1][i]==1){
                q.push({m-1,i});
                visited[m-1][i]=1;
            }
        }
        for(int i=0 ; i<m ; i++){
            if(grid[i][0]==1){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(grid[i][n-1]==1){
                q.push({i,n-1});
                visited[i][n-1]=1;
            }
        }
         while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            vector<int> row={x-1,x,x+1,x};
            vector<int> column={y,y-1,y,y+1};
            for(int i=0 ; i<4 ; i++){
                int r=row[i];
                int c=column[i];
                if(r>=0 && c>=0 && r<m && c<n && !visited[r][c] && grid[r][c]){
                    q.push({r,c});
                    visited[r][c]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n; j++){
                if(grid[i][j] && !visited[i][j]) cnt++;
            }
        }
        return cnt;
    }
};