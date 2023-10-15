class Solution {
private:
    int solve(int ind, int walls, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp){
        if(walls <= 0) return 0;
        if(ind == cost.size()) return 1e9;

        if(dp[ind][walls] != -1) return dp[ind][walls];

        int take = cost[ind] + solve(ind+1, walls-time[ind]-1, cost, time, dp);
        int notTake = solve(ind+1, walls, cost, time, dp);

        return dp[ind][walls] = min(take, notTake);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n, cost, time, dp);
    }
};
