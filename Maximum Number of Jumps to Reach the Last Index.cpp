class Solution {
public:
    // int solve(int n, int prev, vector<int>& nums, int target, vector<vector<int>>& dp){
    //     if(n==0){
    //         if(abs(nums[n] - nums[prev])<=target) return 1;
    //         else return -1e8;
    //     }

    //     if(dp[n][prev] != -1) return dp[n][prev];

    //     int notTake = solve(n-1, prev, nums, target, dp);
    //     int take = -1e8;
    //     if(abs(nums[n] - nums[prev])<=target) take = 1 + solve(n-1, n, nums, target, dp);

    //     return dp[n][prev] = max(take, notTake);
    // }
    
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            if(abs(nums[0] - nums[i])<=target) dp[0][i] = 1;
            else dp[0][i] = -1e8;
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){        
                int notTake = dp[i-1][j];
                int take = -1e8;
                if(abs(nums[i] - nums[j])<=target) take = 1 + dp[i-1][i];
                dp[i][j] = max(take, notTake);
            }
        }
        int ans = dp[n-2][n-1]; 
        if(ans > 0) return ans;
        return -1;
    }
};
