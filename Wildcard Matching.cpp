class Solution {
private:
    // bool solve(int n, int m, string& s, string& p, vector<vector<int>>& dp){
    //     if(n == 0 && m == 0) return 1;
    //     if(n > 0 && m == 0) return 0;
    //     if(n == 0 && m > 0){
    //         for(int i=1; i<m; i++){
    //             if(p[i-1] != '*') return 0;
    //         }
    //         return 1;
    //     }

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(p[m-1] == s[n-1] || p[m-1] == '?') return dp[n][m] = solve(n-1, m-1, s, p, dp);
    //     if(p[m-1] == '*'){
    //         return dp[n][m] = (solve(n, m-1, s, p, dp) | solve(n-1, m, s, p, dp));
    //     }
    //     return 0;
    // }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);

        prev[0] = 1;

        for(int j=1; j<=m; j++){
            if(p[j-1] == '*') prev[j] = 1;
            else break;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == s[i-1] || p[j-1] == '?') curr[j] = prev[j-1];
                else if(p[j-1] == '*')
                curr[j] = curr[j-1] | prev[j];
                else curr[j] = 0;
            }
            prev = curr;
        }

        return prev[m];
        // return solve(n, m, s, p, dp);

    }
};
