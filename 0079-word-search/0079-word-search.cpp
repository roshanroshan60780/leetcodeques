class Solution {
private:
    bool func(int idx ,int x , int y, vector<vector<char>>& board, string& word , vector<vector<int>>& visited){
        visited[x][y]=1;
        int ws=word.size();
        int m=board.size();
        int n=board[0].size();
        if(idx==ws-1) return true;
        vector<int> nx={x,x-1,x,x+1};
        vector<int> ny={y-1,y,y+1,y};

        for(int k=0 ; k<4 ; k++){
            if(nx[k]>=0 && nx[k]<m && ny[k]>=0 && ny[k]<n){
                if(word[idx+1]==board[nx[k]][ny[k]] && !visited[nx[k]][ny[k]]){
                    if(idx+1==ws-1) return true;
                    bool temp=func(idx+1,nx[k],ny[k],board,word,visited);
                    if(temp) return true;
                    else visited[nx[k]][ny[k]]=0;
                }
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        queue<pair<int,pair<int,int>>> q;
        int m=board.size();
        int n=board[0].size();
        int ws=word.size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j]==word[0]){
                    if(func(0,i,j,board,word,visited)) return true;
                    visited[i][j]=0;
                }
            }
        }
        return false;
        
    }
};