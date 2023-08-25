class Solution {
private:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(k >= s3.size()) return 1;
        if(i >= s1.size() && j >= s2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        bool take1 = 0, take2 = 0;
        if(s1[i] == s3[k])
        take1 = solve(i+1, j, k+1, s1, s2, s3, dp);
        if(s2[j] == s3[k])
        take2 = solve(i, j+1, k+1, s1, s2, s3, dp);

        return dp[i][j] = take1 | take2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != s3.size()) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};
