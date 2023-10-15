#define MOD 1000000007
#define ll long long
class Solution {
private:
    int solve(int ind, int steps, int n, vector<vector<int>>& dp){
        if(ind == n || ind < 0 || ind>steps) return 0;
        if(steps == 0){
            if(ind == 0) return 1;
            else return 0;
        }

        if(dp[ind][steps] != -1) return dp[ind][steps];

        ll left = solve(ind-1, steps-1, n, dp)%MOD;
        ll right = solve(ind + 1, steps - 1, n, dp)%MOD;
        ll stay = solve(ind, steps-1, n, dp)%MOD;

        return dp[ind][steps] = (left + right + stay)%MOD;
    }
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(steps +1, -1));
        return solve(0, steps, arrLen, dp);
    }
};
