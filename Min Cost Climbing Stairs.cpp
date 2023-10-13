class Solution {
private:
    int solve(int ind, vector<int>& cost, int n, vector<int>& dp){
        if(ind > n-1) return 0;

        if(dp[ind] != -1) return dp[ind];

        int first = solve(ind+1, cost, n, dp);
        int second = solve(ind+2, cost, n, dp);

        return dp[ind] = cost[ind] + min(first, second);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int zero = solve(0, cost, n, dp);
        int one = solve(1, cost, n, dp);
        return min(zero, one);
    }
};
