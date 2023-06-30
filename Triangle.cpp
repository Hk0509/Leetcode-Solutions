class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    //     if(i == triangle.size()-1) return triangle[i][j];

    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int down = triangle[i][j] + solve(i+1, j, triangle, dp);
    //     int diag = triangle[i][j] + solve(i+1, j+1, triangle, dp);

    //     return dp[i][j] = min(down, diag);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> prev(n, 0), curr(n, 0);

        for(int i=0; i<n; i++){
            prev[i] = triangle[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0 ; j--){
                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j+1];

                curr[j] = min(down, diag);
            }
            prev = curr;
        }
        return prev[0];

        // return solve(0, 0, triangle, dp);
    }
};
