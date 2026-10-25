class Solution {
private:
    bool isNotparent(int r, int c, int pr, int pc){
        if(r==pr && pc==c) return false;
        return true;
    }
    bool dfs(int r, int c,int pr , int pc, vector<vector<char>>& grid, vector<vector<int>>& vis,
             int pathlen) {

        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
        char target = grid[r][c];
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        bool ans = false;
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;
            if (grid[nr][nc]==target && vis[nr][nc] && isNotparent(nr,nc,pr,pc) && pathlen  >= 4)
                return true;
            if (!vis[nr][nc] && grid[nr][nc] == target) {
                ans = dfs(nr, nc,r,c, grid, vis, pathlen + 1);
                if (ans)
                    return true;
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        bool ans = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j])
                    ans = dfs(i, j,-1,-1, grid, vis, 1);
                if (ans)
                    return true;
            }
        }
        return false;
    }
};