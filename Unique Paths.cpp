class Solution {
public:
    // int solve(int m, int n, vector<vector<int>>& dp){
    //     if(m==0 && n==0) return 1;
    //     if(m<0 || n<0) return 0;

    //     if(dp[m][n] != -1) return dp[m][n];

    //     return dp[m][n] = solve(m, n-1, dp) + solve(m-1, n, dp);
    // }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            int left = 0, up = 0;
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) continue;
                if(j!=0) left = dp[i][j-1];
                if(i!=0) up = dp[i-1][j];
                dp[i][j] = left + up;
            }
        }
        return dp[m-1][n-1];
        // return solve(m-1, n-1, dp);
    }
};
