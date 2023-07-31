class Solution {
private:
    // int solve(int n, int m, string& s1, string& s2, vector<vector<int>>& dp){
    //     if(n == 0 || m == 0) return 0;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(s1[n-1] == s2[m-1]) return dp[n][m] = int(s1[n-1]) + solve(n-1, m-1, s1, s2, dp);
    //     int notSame =  max(solve(n-1, m, s1, s2, dp), solve(n, m-1, s1, s2, dp));

    //     return dp[n][m] = notSame;
    // }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        int sum1 = 0, sum2 = 0;
        for(int i=0; i<n; i++) sum1 += int(s1[i]);
        for(int j=0; j<m; j++) sum2 += int(s2[j]);

        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])
                    curr[j] = int(s1[i-1]) + prev[j-1];
                else
                    curr[j] =  max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return (sum1 + sum2) - 2*prev[m];
    }
};
