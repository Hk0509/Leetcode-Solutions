class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int* delR, int* delC){
        int n = grid.size(), m = grid[0].size(), count = 0;
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || !grid[i][j]) return 0;
        vis[i][j] = 1;
        count += grid[i][j];

        for(int ind = 0; ind<4; ind++){
            int newR = i + delR[ind];
            int newC = j + delC[ind];
            // count += grid[newR][newC];

            count += dfs(newR, newC, grid, vis, delR, delC);
        }
        return count;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int delR[4] = {-1, 0, 1, 0};
        int delC[4] = {0, -1, 0, 1}; 
        int maxi = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    maxi = max(maxi, dfs(i, j, grid, vis, delR, delC));
                }
            }
        }
        return maxi;
    }
};
