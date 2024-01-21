class Solution {
public:
    int dp[101];
    int solve(int n, vector<int>& nums){
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int take = nums[n] + solve(n-2, nums);
        int notTake = solve(n-1, nums);

        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(n-1, nums);
    }
};
