class Solution {
public:
    // int solve(int n, int m, string& s, string& s2, vector<vector<int>>& dp){
    //     if(n == 0 || m == 0) return 0;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(s[n-1] == s2[m-1]) return dp[n][m] = 1 + solve(n-1, m-1, s, s2, dp);
    //     else return dp[n][m] = max(solve(n-1, m, s, s2, dp), solve(n, m-1, s, s2, dp));
    // }

    int longestPalindrome(string s){
        int n = s.size();
        string s2;
        for(int i=n-1; i>=0; i--) s2+=s[i];
        // vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        vector<int>prev(n+1, 0), curr(n+1, 0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){       
            if(s[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = max(curr[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
    }

    int minInsertions(string s) {
        int x = longestPalindrome(s);
        return s.size() - x;
    }
};
