class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[51][51][51];
    int solve(int i, int j, int n, int m, int moves){
        if(moves < 0) return 0;
        if(i < 0 || j < 0 || i > n-1 || j > m-1) return 1;

        if(dp[i][j][moves] != -1) return dp[i][j][moves];

        int l = solve(i-1, j, n, m, moves-1);
        int r = solve(i+1, j, n, m, moves-1);
        int u = solve(i, j+1, n, m, moves-1);
        int d = solve(i, j-1, n, m, moves-1);

        return dp[i][j][moves] = (((l + r)%mod + u)%mod + d)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, m, n, maxMove);
    }
};
