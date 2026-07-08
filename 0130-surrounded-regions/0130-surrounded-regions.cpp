class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n));
        for(int i=0 ; i<n ; i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(board[m-1][i]=='O'){
                q.push({m-1,i});
                visited[m-1][i]=1;
            }
        }
        for(int i=0 ; i<m ; i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(board[i][n-1]=='O'){
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
                if(r>=0 && c>=0 && r<m && c<n && !visited[r][c] && board[r][c]=='O'){
                    q.push({r,c});
                    visited[r][c]=1;
                }
            }
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n; j++){
                if(!visited[i][j]) board[i][j]='X';
            }
        }
    }
};