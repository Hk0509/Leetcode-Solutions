class Solution {
public:
    bool solve(int n, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(n == 0) return (sum == nums[n]);
        if(sum == 0) return 1;

        if(dp[n][sum] != -1) return dp[n][sum];

        bool notTake = solve(n-1, sum, nums, dp);
        bool take = 0;
        if(nums[n] <= sum)
        take = solve(n-1, sum - nums[n], nums, dp);

        return dp[n][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];

        if(sum & 1) return 0;
        else{
            vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
            return solve(n-1, sum/2, nums, dp);
        }
    }
};
