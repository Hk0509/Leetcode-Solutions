class Solution {
private:
    // void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis, int* delR, int* delC){
    //     int n = grid.size(), m = grid[0].size();
    //     if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == 1 || grid[i][j] == '0') return ;

    //     for(int ind=0; ind<4; ind++){
    //         vis[i][j] = 1;
    //         dfs(i+delR[ind], j+delC[ind], grid, vis, delR, delC);
    //     }
    // }

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis, int* delR, int* delC){
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int ind=0; ind<4; ind++){
                int newR = r + delR[ind];
                int newC = c + delC[ind];
                if(newR >= 0 && newR < n && newC>=0 && newC<m &&
                 grid[newR][newC] == '1' && !vis[newR][newC]){
                    vis[newR][newC] = 1;
                    q.push({newR, newC});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int delR[4] = {-1, 0, 1, 0};
        int delC[4] = {0, -1, 0, 1};
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i, j, grid, vis, delR, delC);
                }
            }
        }
        return count;
    }
};
