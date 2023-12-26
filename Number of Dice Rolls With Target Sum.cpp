#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[31][1001];
    
    int solve(int n, int k, int target){
        if(n == 0 && target == 0) return 1;
        if(n == 0 || target < n) return 0;
        
        if(dp[n][target] != -1) return dp[n][target];

        int take = 0;
        for(int i=1; i<=k; i++){
            if(target - i >= 0)
            take = (take % mod + solve(n-1, k, target - i)%mod) %mod;
        }

        return dp[n][target] =  (take)%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target)%mod;
    }
};
