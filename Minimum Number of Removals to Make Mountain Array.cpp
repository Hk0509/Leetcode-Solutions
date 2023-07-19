class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        for(int i=0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[i] > nums[prev] && dp1[i] < dp1[prev] + 1){
                    dp1[i] = dp1[prev] + 1;
                }
            }
        }

       for(int i=n-1; i>=0; i--){
            for(int prev = n-1; prev>i; prev--){
                if(nums[i] > nums[prev] && dp2[i] < dp2[prev] + 1){
                    dp2[i] = dp2[prev] + 1;
                }
            }
        }

        int maxi = -1e8;
        for(int i=0; i<n; i++){
            if(dp1[i] != 1 && dp2[i] != 1)
            maxi = max(dp1[i] + dp2[i] - 1, maxi);
        }
        return nums.size()-maxi;
    }
};
