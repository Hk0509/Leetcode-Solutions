class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int count = 2;
        int mon = money;
        for(auto it: prices)
        {
                if(count == 0) return money;
                if(it>money) return mon;
                money -= it;
                count --;
        }
        return money;
    }
};
