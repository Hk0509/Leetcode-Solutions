class Solution {
public:
    // int solve(int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
    //     if(n < 0 || m < 0) return 0;
    //     if(obstacleGrid[n][m] == 1) return 0;
    //     if(n == 0 && m == 0) return 1;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     int up = solve(n-1, m, obstacleGrid, dp);
    //     int left = solve(n, m-1, obstacleGrid, dp);

    //     dp[n][m] = up + left;
    //     return dp[n][m];
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1)); 
        // dp[0][0] = 1;
        vector<int> prev(m, 0);

        for(int i=0; i<n; i++){
            vector<int> curr(m, 0);
            for(int j=0; j<m; j++){
                if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else{
                    if(i==0 && j==0) curr[j] = 1;
                    else{
                        int up = 0, left = 0;
                        if(i>0) up = prev[j];
                        if(j>0) left = curr[j-1];
                        curr[j] = up + left;
                    }
                }
            }
            prev = curr;
        }
        return prev[m-1];
        // return solve(n-1, m-1, obstacleGrid, dp);
    }
};
