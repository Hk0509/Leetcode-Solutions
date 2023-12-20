class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int leftover = money - (prices[0] + prices[1]);
        return leftover < 0 ? money : leftover;
    }
};

// class Solution {
// public:
//     int buyChoco(vector<int>& prices, int money) {
//         sort(prices.begin(), prices.end()); //Sort the array
//         int count = 2;
//         int mon = money;
//         //Iterate over prices vector
//         for(auto it: prices)
//         {
//                 if(count == 0) return money;
//                 if(it>money) return mon;
//                 money -= it;
//                 count --;
//         }
//         return money;
//     }
// };
