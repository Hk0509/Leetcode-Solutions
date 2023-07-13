class Solution {
public:
    // int solve(int i, bool buy, vector<int>& prices, vector<vector<int>>& dp){
    //     if(i == prices.size()) return 0;

    //     if(dp[i][buy] != -1) return dp[i][buy];

    //     if(buy){
    //         return dp[i][buy] = max(-prices[i] + solve(i+1, 0, prices, dp), solve(i+1, 1, prices, dp));
    //     }
    //     else{
    //         return dp[i][buy] = max(prices[i] + solve(i+1, 1, prices, dp), solve(i+1, 0, prices, dp));
    //     }
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currBuy = 0, nextBuy = 0,  currNotBuy = 0, nextNotBuy = 0;

        for(int i=n-1; i>=0; i--){
            currBuy = max(-prices[i] + nextNotBuy, nextBuy);
            currNotBuy = max(prices[i] + nextBuy, nextNotBuy);
            nextBuy = currBuy, nextNotBuy = currNotBuy;
        }
        return currBuy;
    }
};
