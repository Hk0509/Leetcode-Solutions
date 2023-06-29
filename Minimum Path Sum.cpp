// #define MOD 1000000007
class Solution {
public:
    // int solve(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(n == 0 && m == 0) return grid[n][m];
    //     if(n < 0 || m < 0) return INT_MAX;
        
    //     if(dp[n][m] != -1) return dp[n][m]; 

    //     int up = grid[n][m] + solve(n-1, m, grid, dp) % MOD;
    //     int left = grid[n][m] + solve(n, m-1, grid, dp) % MOD;

    //     dp[n][m] = min(up, left);
    //     return dp[n][m];
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<int> prev(m, 0);

        for(int i=0; i<n; i++){
            vector<int>curr(m, 0);
            for(int j=0; j<m; j++){
                if(i == 0 && j == 0) curr[j] = grid[i][j];
                else{
                    int up = grid[i][j], left = grid[i][j];
                    if(i > 0) up += prev[j];
                    else up = INT_MAX;
                    if(j > 0) left += curr[j-1];
                    else left = INT_MAX;
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
        // return solve(n-1, m-1, grid, dp);
    }
};
