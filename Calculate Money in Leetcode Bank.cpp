//O(1) Solution
class Solution {
public:
    int totalMoney(int n) { 
        double rem = n%7; //Remaining Days
        n = n - n%7; //Remove extra days to make complete weeks
        double weeks = n/7; // Number of weeks
        //Derived Sum of series for weeks
        double ans = 7*(3*weeks + (weeks * (weeks + 1)/2));  
        //Remaining Days
        ans += rem/2 * (2*(weeks+1) + (rem - 1));
        return ans;
    }
};

// O(N) Solution
// class Solution {
// public:
//     int totalMoney(int n) {
//         double ans = 0, curr = 1;
//         double rem = n%7;
//         n = n - n%7;
//         for(double i=1; i<=n; i+=7){
//             double weekSum = 3.5 * (2*curr + (6));
//             curr++;
//             ans += weekSum;
//         }
//         ans += rem/2 * (2*curr + (rem - 1));
//         return ans;
//     }
// };
