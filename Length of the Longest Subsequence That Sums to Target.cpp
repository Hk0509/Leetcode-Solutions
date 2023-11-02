#define ll long long
class Solution {
public:
    int solve(int n, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(target == 0) return 0;
        if(n < 0) return -1e9;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        ll take = -1e9; 
        if(target - nums[n] >= 0){
            take = 1 + solve(n-1, nums, target-nums[n], dp);
        }
        ll notTake = solve(n-1, nums, target, dp);
        
        return dp[n][target] = max(take, notTake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        int ans = solve(n-1, nums, target, dp);
        if(ans <= 0) return -1;
        return ans;
    }
};
