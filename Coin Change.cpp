class Solution {
public:
    // int solve(int n, int amount, vector<int>& coins, vector<vector<int>>& dp){
    //     if(n == 0){
    //         if(amount % coins[0] == 0) return amount/coins[0];
    //         return 1e9;
    //     }

    //     if(dp[n][amount] != -1) return dp[n][amount];

    //     int notTake = solve(n-1, amount, coins, dp);
    //     int take = 1e9;
    //     if(coins[n] <= amount) take = 1 + solve(n, amount - coins[n], coins, dp);

    //     return dp[n][amount] = min(take, notTake);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1, 0), curr(amount+1, 0);

        for(int i=0; i <= amount; i++){
            if(!(i % coins[0])) prev[i] = i/coins[0];
            else prev[i] = 1e9;  
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int notTake = prev[j];
                int take = 1e9;
                if(coins[i] <= j) take = 1 + curr[j-coins[i]];
                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        if(ans == 1e9) return -1;
        return ans;
    }
};
