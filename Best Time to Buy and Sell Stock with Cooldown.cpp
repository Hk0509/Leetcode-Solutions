class Solution {
public:
    // int solve(int i, bool buy, vector<int>& prices, int n, vector<vector<int>>& dp){
    //     if(i >= n) return 0;

    //     if(dp[i][buy] != -1) return dp[i][buy];

    //     if(buy){
    //         return dp[i][buy] = max(-prices[i] + solve(i+1, 0, prices, n, dp), solve(i+1, 1, prices, n, dp));
    //     }
    //     else{
    //         return dp[i][buy] = max(prices[i] + solve(i+2, 1, prices, n, dp), solve(i+1, 0, prices, n, dp));
    //     }
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+2, vector<int>(2, 0));
        vector<int> next1(2, 0), next2(2, 0), curr(2, 0);

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    curr[buy] = max(-prices[i] + next1[0], next1[1]);
                }
                else{
                    curr[buy] = max(prices[i] + next2[1], next1[0]);
                }
            }
            next2 = next1, next1 = curr;
        } 
        return curr[1];
        // return solve(0, 1, prices, n, dp);
    }
};
