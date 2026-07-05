class Solution {
private:
    int bfs(vector<vector<int>>& grid , vector<int> row , vector<int> col ){
        queue<pair<int,int>> q;
        int ans=-1;
        int n=row.size();
        for(int i=0 ; i<n ; i++){
            q.push({row[i],col[i]});
        }
        int rowcnt=grid.size();
        int colcnt=grid[0].size();
        while(!q.empty()){
            int s=q.size();
            for(int i=0 ; i<s ; i++){
                pair<int,int> temp=q.front();
                q.pop();
                int r=temp.first;
                int c=temp.second;
                if(r>0 && grid[r-1][c]==1){
                    q.push({r-1,c});
                    grid[r-1][c]=2;
                }
                if(r<rowcnt-1 && grid[r+1][c]==1){
                    q.push({r+1,c});
                    grid[r+1][c]=2;
                }
                if(c>0 && grid[r][c-1]==1){
                    q.push({r,c-1});
                    grid[r][c-1]=2;
                }
                if(c<colcnt-1 && grid[r][c+1]==1){
                    q.push({r,c+1});
                    grid[r][c+1]=2;
                }
            }
            ans++;

        }
        return ans;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rowcnt=grid.size();
        int colcnt=grid[0].size();
        vector<int> row,col;
        int flagfresh=0;
        for(int i=0 ; i<rowcnt ; i++){
            for(int j=0 ; j<colcnt ; j++){
                if(grid[i][j]==1) flagfresh=1;
                if(grid[i][j]==2){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        if(!flagfresh) return 0;
        if(row.size()==0) return -1;

        int ans=bfs(grid,row,col);

        for(int i=0 ; i<rowcnt ; i++){
            for(int j=0 ; j<colcnt ; j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};