class Solution {
private:
    void traverse(vector<vector<char>>& grid, int i , int j , vector<vector<char>>& visited){
        int numofrow=grid.size();
        int numofcol=grid[0].size();
        visited[i][j]='1';
        if(i>0 && grid[i-1][j]=='1' && visited[i-1][j]=='0') traverse(grid,i-1,j,visited);
        if(i<numofrow-1 && grid[i+1][j]=='1' && visited[i+1][j]=='0') traverse(grid,i+1,j,visited);
        if(j>0 && grid[i][j-1]=='1' && visited[i][j-1]=='0') traverse(grid,i,j-1,visited);
        if(j<numofcol-1 && grid[i][j+1]=='1' && visited[i][j+1]=='0') traverse(grid,i,j+1,visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int numofrow=grid.size();
        int numofcol=grid[0].size();
        int ans=0;
        vector<vector<char>> visited(numofrow,vector<char>(numofcol,'0'));
            for(int i=0 ; i<numofrow ; i++){
                for(int j=0 ; j<numofcol ; j++){
                    if(grid[i][j]=='1' && visited[i][j]=='0'){
                        ans++;
                        traverse(grid,i,j,visited);
                    }
                }
            }
        return ans;
    }
};