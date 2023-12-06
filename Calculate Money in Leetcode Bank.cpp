class Solution {
public:
    int totalMoney(int n) {
        double ans = 0, curr = 1;
        double rem = n%7;
        n = n - n%7;
        for(double i=1; i<=n; i+=7){
            double weekSum = 3.5 * (2*curr + (6));
            curr++;
            ans += weekSum;
        }
        ans += rem/2 * (2*curr + (rem - 1));
        return ans;
    }
};
