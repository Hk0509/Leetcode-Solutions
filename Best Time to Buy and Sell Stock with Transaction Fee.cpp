class Solution {
public:
    // int solve(int i, bool buy, int fee, vector<int>& prices){
    //     if(i == prices.size()) return 0;

    //     if(buy){
    //         return max(-prices[i] + solve(i+1, 0, fee, prices), solve(i+1, 1, fee, prices));
    //     }
    //     else{
    //         return max(prices[i] - fee + solve(i+1, 1, fee, prices), solve(i+1, 0, fee, prices));
    //     }
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int nextBuy = 0, nextNotBuy = 0, currBuy = 0, currNotBuy = 0;
        
        for(int i = n-1; i>=0; i--){
            currBuy = max(-prices[i] + nextNotBuy, nextBuy);
            currNotBuy = max(prices[i] - fee + nextBuy, nextNotBuy);
            nextBuy = currBuy, nextNotBuy = currNotBuy;     
        }
        return currBuy;
    }
};
