class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxi = -1e8, lastIndex = 0;
        vector<int> dp(n, 1), hash(n);
        for(int i=1; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev<i; prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        return ans;
    }
};
