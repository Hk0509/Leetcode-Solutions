// #define ll long long
class Solution {
private:
    int solve(int n, int m, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(n<0 || m<0) return 0;

        if(dp[n][m] != -1) return dp[n][m];
        
        int take = (nums1[n] * nums2[m]) + solve(n-1, m-1, nums1, nums2, dp);
        int notTake = max(solve(n-1, m, nums1, nums2, dp), solve(n, m-1, nums1, nums2, dp));
        return dp[n][m] = max(take, notTake);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int cntNeg1 = 0, cntNeg2 = 0, maxNeg = -1e9, minPos = 1e9;

        for(auto it: nums1){
            if(it < 0){
                cntNeg1++;
                maxNeg = max(maxNeg, it);
            }
            else{
                minPos = min(minPos, it);
            }
        }
        for(auto it: nums2){
            if(it < 0){
                cntNeg2++;
                maxNeg = max(maxNeg, it);
            }
            else{
                minPos = min(minPos, it);
            }
        }

        if( (cntNeg1 == 0 && cntNeg2 == nums2.size()) || 
        (cntNeg2 == 0 && cntNeg1 == nums1.size()) ){
            return minPos * maxNeg;
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, nums1, nums2, dp);
    }
};
