class Solution {
public:
    int dp[101];
    int solve(int i, int n, string &s){
        if(i == n) return 1;
        if(i > n) return 0;
        if(s[i] == '0' ||  (s[i] >= '3' && s[i+1] == '0')) return 0; 

        if(dp[i] != -1) return dp[i];

        int take = 0, notTake = 0;
        if(i != n-1 && (s[i] == '2' && s[i+1] <= '6') || (s[i] == '1') || s[i+1] == '0'){
            take = solve(i+2, n, s);
        }
        if(s[i+1] != '0')
        notTake = solve(i+1, n, s);

        return dp[i] = take + notTake;
    }
    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, s);
    }
};
