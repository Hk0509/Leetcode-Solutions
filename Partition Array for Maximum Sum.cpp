class Solution {
public:
    int n;
    int dp[501];
    int solve(int i, int k, vector<int>& arr){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int j = min(i + k, n), maxi = 0, ans = 0;
        for(int ind = i; ind < j; ind++){
            maxi = max(maxi, arr[ind]);
            ans = max(ans, maxi * (ind - i + 1) + solve(ind+1, k, arr));
        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1,sizeof(dp));
       return solve(0, k, arr);
    }
};
