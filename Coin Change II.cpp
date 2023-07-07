class Solution {
public:
    // int solve(int n, int amount, vector<int>& coins, vector<vector<int>>& dp){
    //     if(n == 0) return (!(amount % coins[n]));
    //     if(amount == 0) return 1;

    //     if(dp[n][amount] != -1) return dp[n][amount];

    //     int notTake = solve(n-1, amount, coins, dp);
    //     int take = 0;
    //     if(coins[n] <= amount) take = solve(n, amount - coins[n], coins, dp);

    //     return dp[n][amount] = take + notTake;
    // }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        vector<int> prev(amount+1, 0), curr(amount+1, 0);

        for(int i=0; i <= amount; i++){
            if(!(i % coins[0])) prev[i] = 1;  
        }

        for(int i=1; i<n; i++){
            for(int j = 0; j <= amount; j++){
                int notTake = prev[j];
                int take = 0;
                if(coins[i] <= j) take = curr[j-coins[i]];
                curr[j] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
        // return solve(n-1, amount, coins, dp);
    }
};
