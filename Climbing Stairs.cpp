// 18 Feb
class Solution {
public:
    int dp[50];
    int solve(int n){
        if(n < 0) return 0;
        if(n <= 0) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1) + solve(n-2);
    }
    int climbStairs(int n){
        memset(dp, -1, sizeof(dp));
       return solve(n);
    }
};


// class Solution {
// private:
//     int solve(int n, vector<int>& dp){
//         if(n <= 0) return n+1;
        
//         if(dp[n] != -1) return dp[n];

//         int one = solve(n-1, dp);
//         int two = solve(n-2, dp);

//         return dp[n] = one + two;
//     }
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1, -1);
//         return solve(n, dp);
//     }
// };
