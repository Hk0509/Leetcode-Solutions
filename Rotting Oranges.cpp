class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delR[4] = {-1, 0, 1, 0};
        int delC[4] = {0, -1, 0, 1};
        int ans = 0;
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for(int ind = 0; ind < 4; ind++){
                int newR = r + delR[ind];
                int newC = c + delC[ind];

                if(newR >= 0 && newR < n && newC >=0 && newC < m 
                && vis[newR][newC] == 0 && grid[newR][newC] == 1){
                    vis[newR][newC] = 2;
                    q.push({{newR, newC}, t+1});
                }
                ans = max(t, ans);
            }
        }   

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] && vis[i][j] != 2) return -1;
            }
        }

        return ans;
    }
};
