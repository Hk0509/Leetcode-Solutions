class Solution {
public:
    // int solve(int n, int m, vector<vector<int>>& nums, vector<vector<int>>& dp){
    //     if(m<0 || m>nums[0].size()-1) return 1e8;
    //     if(n == 0) return nums[n][m];

    //     if(dp[n][m] != -1e8) return dp[n][m];

    //     int upLeft = nums[n][m] + solve(n-1, m-1, nums, dp);
    //     int upRight = nums[n][m] + solve(n-1, m+1, nums, dp);
    //     int up = nums[n][m] + solve(n-1, m, nums, dp);

    //     return dp[n][m] = min(upLeft, min(upRight, up));
    // }

    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 1e8;
        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int i=0; i<n; i++){
            prev[i] = nums[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int upLeft = nums[i][j], up = nums[i][j], upRight = nums[i][j];

                if(j>0) upLeft += prev[j-1];
                else upLeft = 1e8;

                if(j<n-1) upRight += prev[j+1];
                else upRight = 1e8;

                up += prev[j];

                curr[j] = min(upLeft, min(upRight, up));
            }
            prev = curr;
        }

        for(int i=0; i<n; i++){
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};
