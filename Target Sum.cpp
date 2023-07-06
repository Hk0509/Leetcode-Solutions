class Solution {
public:
    // int solve(int n, int t, vector<int>& nums,  vector<vector<int>>& dp){
    //     if(n == 0){
    //         if(t == 0 && nums[0] == t) return 2;
    //         if(t == 0 || nums[0] == t) return 1;
    //         return 0; 
    //     }

    //     if(dp[n][t] != -1) return dp[n][t];

    //     int notTake = solve(n-1, t, nums, dp);
    //     int take = 0;
    //     if(nums[n] <= t) take = solve(n-1, t - nums[n], nums, dp);

    //     return dp[n][t] = take + notTake;
    // }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum - target < 0 || (sum - target)&1) return 0;

        int t = (sum-target)/2;
        // vector<vector<int>> dp(n, vector<int>(t+1, 0));
        vector<int> prev(t+1, 0);

        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;

        if(nums[0] != 0 && nums[0] <= t) prev[nums[0]] = 1;

        for(int i=1; i<n; i++){
            for(int j=t; j>=0; j--){
                int notTake = prev[j];
                int take = 0;
                if(nums[i] <= j) take = prev[j-nums[i]];

                prev[j] = take + notTake;
            }
            // prev = curr;
        }

        return prev[t];
        // return solve(n-1, t, nums, dp);  //a+b = sum....a-b = target....2a = sum + target
    }
};
