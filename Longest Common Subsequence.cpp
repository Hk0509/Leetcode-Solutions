class Solution {
public:
    // int solve(int n, int m, string& a, string& b, vector<vector<int>>& dp){
    //     if(n == 0 || m == 0) return 0;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(a[n-1] == b[m-1]) return dp[n][m] = (1 + solve(n-1, m-1, a, b, dp));
    //     else return dp[n][m] = (max(solve(n-1, m, a, b, dp), solve(n, m-1, a, b, dp)));
    // }

    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<int>curr(m+1, 0), prev(m+1, 0);

        for(int i=0; i<=n; i++) prev[0] = 0;
        for(int i=0; i<=m; i++) prev[i] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1] == b[j-1]) curr[j] = (1 + prev[j-1]);
                else curr[j] = (max(prev[j], curr[j-1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};
