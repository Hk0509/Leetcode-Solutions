class Solution {
private:
    bool solve(int i, vector<int>& nums, vector<int>& dp){
        if(i<0) return 1;

        if(dp[i] != -1) return dp[i];

        bool first = 0;
        bool second = 0;
        bool third = 0;
        // Checking first condition
        if(i>=1 && nums[i] == nums[i-1]) first = solve(i-2, nums, dp);
        //Checking second condition
        if(i>=2 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2]) second = solve(i-3, nums, dp);
        //Checking third condition
        if(i>=2 && nums[i] == nums[i-1] + 1 && nums[i-1] == nums[i-2] + 1) third = solve(i-3, nums, dp);

        return dp[i] = (first || second || third);
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n-1, nums, dp);
    }
};
