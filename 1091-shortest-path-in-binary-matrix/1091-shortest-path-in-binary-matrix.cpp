class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0]==0){
            q.push({1,{0,0}});
            dis[0][0]=1;
        }
        while(!q.empty()){
            pair<int,pair<int,int>> temp=q.front();
            int d=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            q.pop();
            if(d>dis[x][y]) continue;
            for(int i=-1; i<=1 ; i++){
                int delx=x+i;
                for(int j=-1 ; j<=1 ; j++){
                    int dely=y+j;
                    if((i==0 && j==0) || delx<0 || dely <0 || delx>=n || dely>=n) continue;
                    if(grid[delx][dely] == 0 && d+1<dis[delx][dely]){
                        dis[delx][dely]=d+1;
                        q.push({d+1 , {delx , dely}});
                    }
                }
            }
        }
        if(dis[n-1][n-1]==INT_MAX) return -1;
        return dis[n-1][n-1];
    }
};