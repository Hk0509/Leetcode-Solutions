// 11 Feb update
#define ll long long
class Solution {
public:
    int dp[71][71][71];
    ll solve(ll i, ll j1, ll j2, ll n, ll m, vector<vector<int>>& grid){
        if(i == n) return 0;
        if(i < 0 || j1 < 0 || j2 < 0 || i >= n || j1 >= m || j2 >= m) return -1e9;

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        ll currSum = 0;
        if(j1 == j2){
            currSum = grid[i][j1];
        }
        else{
            currSum = grid[i][j1] + grid[i][j2];
        }

        ll a = currSum + 1ll * solve(i + 1, j1 - 1, j2 - 1, n, m, grid); 
        ll b = currSum + 1ll * solve(i + 1, j1 - 1, j2, n, m, grid);
        ll c = currSum + 1ll * solve(i + 1, j1 - 1, j2 + 1, n, m, grid); 
        ll d = currSum + 1ll * solve(i + 1, j1, j2 - 1, n, m, grid); 
        ll e = currSum + 1ll * solve(i + 1, j1, j2, n, m, grid); 
        ll f = currSum + 1ll * solve(i + 1, j1, j2 + 1, n, m, grid);
        ll g = currSum + 1ll * solve(i + 1, j1 + 1, j2 - 1, n, m, grid); 
        ll h = currSum + 1ll * solve(i + 1, j1 + 1, j2, n, m, grid); 
        ll k = currSum + 1ll * solve(i + 1, j1 + 1, j2 + 1, n, m, grid);

        return dp[i][j1][j2] = max({a,b,c,d,e,f,g,h,k});
    }
    int cherryPickup(vector<vector<int>>& grid) {
       int n = grid.size(), m = grid[0].size();
       memset(dp, -1, sizeof(dp));
       return solve(0, 0, m-1, n, m, grid);
    }
};







// class Solution {
// public:
//     // int solve(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>>& dp){
//     //     if(j1 < 0 || j2 < 0 || j1 > m-1 || j2 > m-1) return -1e8;

//     //     if(i == n-1){
//     //         if(j1 == j2) return grid[i][j1];
//     //         else return grid[i][j1] + grid[i][j2];
//     //     }

//     //     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

//     //     int maxi = -1e8;
//     //     for(int dj1 = -1; dj1 <= 1; dj1++){
//     //         for(int dj2 = -1; dj2 <= 1; dj2++){
//     //             int value = 0;
//     //             if(j1 == j2) value = grid[i][j1];
//     //             else value = grid[i][j1] + grid[i][j2];
//     //             value += solve(i+1, j1+dj1, j2+dj2, grid, n, m, dp);
//     //             maxi = max(maxi, value);
//     //         }
//     //     }
//     //     return dp[i][j1][j2] = maxi;
//     // }

//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
//         vector<vector<int>> front(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

//         for(int j1 = 0; j1 < m; j1++){
//             for(int j2 = 0; j2 < m; j2++){
//                 if(j1 == j2) front[j1][j2] = grid[n-1][j1];
//                 else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
//             }
//         }

//         for(int i = n-2; i>=0; i--){
//             for(int j1 = 0; j1 < m; j1++){
//                 for(int j2 = 0; j2 < m; j2++){
//                     int maxi = -1e8;
//                    for(int dj1 = -1; dj1 <= 1; dj1++){
//                         for(int dj2 = -1; dj2 <= 1; dj2++){
//                             int value = 0;
//                             if(j1 == j2) value = grid[i][j1];
//                             else value = grid[i][j1] + grid[i][j2];
//                             if(j1 + dj1 >= 0 && j2 + dj2 >= 0 && j1 + dj1 < m && j2 + dj2 < m)
//                             value += front[j1 + dj1][j2 + dj2];
//                             else value = -1e8;
//                             maxi = max(maxi, value);
//                         } 
//                     }
//                     curr[j1][j2] = maxi;
//                 }
//             }
//             front = curr;
//         }
        
//         return front[0][m-1];
//         // return solve(0, 0, m-1, grid, n, m, dp);
//     }
// };
