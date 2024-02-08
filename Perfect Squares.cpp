#define ll long long
class Solution {
public:
    ll dp[101][10001];
    long long solve(ll i, ll n){
        if(n == 0) return 0;
        if(i == 0) return 1e9;

        if(dp[i][n] != -1) return dp[i][n];

        ll take = 1e9, notTake = 1e9;
        if(i*i <= n) take = 1 + solve(i, n - (i*i));
        notTake = solve(i-1, n);

        return dp[i][n] = min(take, notTake);
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(sqrt(n), n);
    }
};
