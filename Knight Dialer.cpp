class Solution {
public:
    const int mod = 1e9 + 7;
    long long solve(long long n, long long i, long long j, vector<vector<vector<long long>>>& dp){
        if(i<0 || j >= 3 || i>= 4 || j<0 || (i == 3 && (j == 0 || j == 2))) return 0;
        if(n == 0) return 1;

        if(dp[n][i][j] != -1) return dp[n][i][j];

        long long a = solve(n-1, i+1, j+2, dp)%mod;
        long long b = solve(n-1, i+1, j-2, dp)%mod;
        long long c = solve(n-1, i+2, j+1, dp)%mod;
        long long d = solve(n-1, i+2, j-1, dp)%mod;
        long long e = solve(n-1, i-1, j+2, dp)%mod;
        long long f = solve(n-1, i-1, j-2, dp)%mod;
        long long g = solve(n-1, i-2, j+1, dp)%mod;
        long long h = solve(n-1, i-2, j-1, dp)%mod;

        return dp[n][i][j] = (a+b+c+d+e+f+g+h)%mod;
    }

    int knightDialer(int n) {
        long long ans = 0;
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(5, vector<long long>(4, -1)));
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                ans = (ans + solve(n-1, i, j, dp) %mod)%mod;
            }
        }
        return ans;
    }
};
