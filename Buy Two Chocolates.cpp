//O(n) Solution
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini = 1e9, mini2 = 1e9;
        for(auto it: prices){
            if(it < mini){
                mini2 = mini;
                mini = it;
            }
            else if(it < mini2){
                mini2 = it;
            }
        }
        int left = money - mini - mini2;
        return left < 0 ? money : left;
    }
};

//O(logn) Solution
// class Solution {
// public:
//     int buyChoco(vector<int>& prices, int money) {
//         sort(prices.begin(), prices.end());
//         int leftover = money - (prices[0] + prices[1]);
//         return leftover < 0 ? money : leftover;
//     }
// };

//O(logn) during Contest Solution
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
