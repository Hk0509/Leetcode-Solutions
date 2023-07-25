#define ll long long
class Solution {
public:
    ll solve(int n, ll sum, vector<vector<ll>>& dp){
        if(n == 1) return n;

        if(dp[n][sum] != -1) return dp[n][sum];

        int take = -1e8;
        if(n <= sum) take = n * solve(n, sum-n, dp);
        int notTake = solve(n-1, sum, dp);

        return dp[n][sum] = max(take, notTake);
    }

    int integerBreak(int n) {
        if(n<4) return n-1;
        // vector<int> nums;
        // for(int i=0; i<n; i++) nums.push_back(i+1);
        vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
        return (int)solve(n, n, dp);
    }
};
